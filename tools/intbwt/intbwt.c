#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

/* Makes suffix array p of x. x becomes inverse of p. p and x are both of size
   n+1. Contents of x[0...n-1] are integers in the range l...k-1. Original
   contents of x[n] is disregarded, the n-th symbol being regarded as
   end-of-string smaller than all other symbols.*/
void suffixsort(int *x, int *p, int n, int k, int l);

int * genbwt(int* input, unsigned int n)
{
    int i;
    
    int * input_copy = calloc(n+1, sizeof(int));
    if (input_copy == NULL)
        return NULL;
    
    memcpy(input_copy, input, n * sizeof(int));
    input_copy[n] = -1; // may not be needed, precautionary EOS symbol
    
    int * suf_array = calloc(n+1, sizeof(int));
    if (suf_array == NULL)
        return NULL;
    
    
    suffixsort(input_copy, suf_array, n, INT_MAX, 0);
    free(input_copy);
    
    int * bwt = calloc(n, sizeof(int));
    int out_index = 0;
    for (i = 0; i < n+1; i++)
    {
        if (suf_array[i] != 0)
        {
            int bwt_index = (suf_array[i] - 1) % n;
            bwt[out_index] = input[bwt_index];
            out_index++;
        }
    }
    
    free(suf_array);
    
    return bwt;
}

int main(int argc, char **argv)
{   
    char * filename;
    FILE * input_fp;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: intbwt <inputfile>\n");
        exit(1);
    }
    else
    {
        filename = argv[1];
        input_fp = fopen(filename, "r");
        if (input_fp == NULL)
        {
            fprintf(stderr, "Unable to open file %s\n", filename);
        }
    }
    
    //Get file length
    fseek(input_fp, 0, SEEK_END);
    unsigned long file_length = ftell(input_fp);
    fseek(input_fp, 0, SEEK_SET);
    
    unsigned int n = file_length/(sizeof(int));
    
    int * buffer = calloc(n, sizeof(int));
    fread(buffer, sizeof(int), n, input_fp);
    fclose(input_fp);
    
    int * bwt = genbwt(buffer, n);
    free(buffer);
    
    // Output file
    int filename_len = strlen(filename);
    char * extension = ".bwt";
    int ext_len = strlen(extension);
    char * output_filename = malloc(filename_len + ext_len + 1);
    assert(output_filename != NULL);
    strcpy(output_filename, filename);
    strcat(output_filename, extension);
    FILE * output_fp = fopen(output_filename, "w");
    fwrite(bwt, sizeof(int), n, output_fp);
    fclose(output_fp);
    
    free(bwt);
    
    return 0;
}