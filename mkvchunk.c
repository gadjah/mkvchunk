#include <stdio.h>


int main(int argc, char* argv[]) {

    FILE *in, *out;
    long int pos = 0;

    in = fopen(argv[1],"rb");
    out = fopen(argv[2], "wb");

    fseek(in, 0L, SEEK_END);
    long int endpos = ftell(in);
    fseek(in, 0L, SEEK_SET);

    int c, x=0;

    int code[4] = {0x1A, 0x45, 0xdf, 0xa3};

    while (1) {
        c = getc(in);
        pos++;
        if (c == code[x]) {
            x++;
            if (x == 4) {
                /* we have found the mkv header */
                break;
            }
            else continue;
        }
        x = 0;

    }

    while (pos < endpos) {
        c = getc(in);
        pos++;
        putc(c, out);
    }

    fclose(in);
    fclose(out);
    return 0;

}
