#include <stdio.h>
#include <stdlib.h>


typedef struct header 
{
    char chunk_id[4];
    int chunk_size;
    char format[4];
    char subchunk1_id[4];
    int subchunk1_size;
    short int audio_format;
    short int num_channels;
    int sample_rate;
    int byte_rate;
    short int block_align;
    short int bits_per_sample;
    short int extra_param_size;
    char subchunk2_id[4];
    int subchunk2_size;
} header;

typedef struct header* header_p;

void scale_wav_file(char * input, float factor, int is_8bit)
{
    FILE * infile = fopen(input, "rb");
    FILE * outfile = fopen("outfile.wav", "wb");

    int BUFSIZE = 4000, i, MAX_8BIT_AMP = 255, MAX_16BIT_AMP = 32678;

    // used for processing 8-bit file
    unsigned char inbuff8[BUFSIZE], outbuff8[BUFSIZE];

    // used for processing 16-bit file
    short int inbuff16[BUFSIZE], outbuff16[BUFSIZE];

    // header_p points to a header struct that contains the file's metadata fields
    header_p meta = (header_p)malloc(sizeof(header));

    if (infile)
    {

        // read and write header data
        fread(meta, 1, sizeof(header), infile);
        fwrite(meta, 1, sizeof(meta), outfile);

        while (!feof(infile))
        {
            if (is_8bit)
            {
                fread(inbuff8, 1, BUFSIZE, infile);   
            } else {
                fread(inbuff16, 1, BUFSIZE, infile);      
            }

            // scale amplitude for 8/16 bits
            for (i=0; i < BUFSIZE; ++i)
            {
                if (is_8bit)
                {
                    outbuff8[i] = factor * inbuff8[i];
                    if ((int)outbuff8[i] > MAX_8BIT_AMP)
                    {
                        outbuff8[i] = MAX_8BIT_AMP;
                    }
                } else {
                    outbuff16[i] = factor * inbuff16[i];
                    if ((int)outbuff16[i] > MAX_16BIT_AMP)
                    {
                        outbuff16[i] = MAX_16BIT_AMP;
                    } else if ((int)outbuff16[i] < -MAX_16BIT_AMP) {
                        outbuff16[i] = -MAX_16BIT_AMP;
                    }
                }
            }

            // write to output file for 8/16 bit
            if (is_8bit)
            {
                fwrite(outbuff8, 1, BUFSIZE, outfile);
            } else {
                fwrite(outbuff16, 1, BUFSIZE, outfile);
            }
        }
    }

    // cleanup
    if (infile) { fclose(infile); }
    if (outfile) { fclose(outfile); }
    if (meta) { free(meta); }
}

int main (int argc, char const *argv[])
{
    char infile[] = "test.wav";
    float factor;
    printf ("Coloque o fator: ");
	scanf("%f", &factor);
    scale_wav_file(infile, factor, 0);
    return 0;
}
