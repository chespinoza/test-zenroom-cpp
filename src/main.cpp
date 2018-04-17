#include <iostream>
#include <fstream>
#ifdef __cplusplus
extern "C" {
#endif

#include "zenroom.h"
#ifdef __cplusplus
}
#endif

static char *Readfile(const char *filename)
{
    std::ifstream fin(filename);
    std::filebuf *pbuff = fin.rdbuf();
    std::size_t size = pbuff->pubseekoff(0, fin.end, fin.in);
    pbuff->pubseekpos(0, fin.in);
    char *buffer = new char[size];

    pbuff->sgetn(buffer, size);
    fin.close();
    return buffer;
}

int main(int argc, char *argv[])
{

    char *script = Readfile("scripts/hello.lua");
    char *data = (char *)"{\"val\":1}";
    char *keys = Readfile("keys/device_keys.json");

    return zenroom_exec(script, NULL, keys, data, 1);
}
