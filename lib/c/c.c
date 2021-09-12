#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "c.h"
#include <sys/stat.h>
#include <sys/types.h>

void create_c_project() {
    mkdir("src", 0777);
    mkdir("lib", 0777);
    mkdir("bin", 0777);

    FILE *fp = fopen("src/main.c", "w");

    fprintf(fp, "#include <stdio.h>\n\nint main(){\n\tprintf(\"Hello, World!\\n\");\n\n\treturn 0;\n}\n");
    system("git init");

    fclose(fp);

    fp = fopen("compile_flags.txt", "w");
    fprintf(fp, "-std=c99\n-g\n-O3\n-Wall\n-Wextra\n-Wpedantic\n-Wstrict-aliasing\n-Ilib/");
    fclose(fp);

    fp = fopen("Makefile", "w");
    fprintf(fp, "CC=gcc\nCFLAGS = -std=c99 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing\n");
    fprintf(fp, "CFLAGS += -I lib/\n");
    fprintf(fp, "SRC = src/main.c\n");
    fprintf(fp, "BIN = bin\n");
    fprintf(fp, "NAME = main\n\n");
    fprintf(fp, ".PHONY: all clean\n\n");
    fprintf(fp, "all: build\n");
    fprintf(fp, "run: all\n\t$(BIN)/main\n\n");
    fprintf(fp, "build:\n\t$(CC) -o $(BIN)/$(NAME) $(SRC) $(CFLAGS)\n\n");
    fprintf(fp, "clean:\n\t rm -rf $(BIN)");
    fclose(fp);
}
