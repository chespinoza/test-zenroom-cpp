#include <cstring>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

#include "zenroom.h"
#ifdef __cplusplus
}
#endif

static char *Readfile(const char *filename) {
  std::ifstream fin(filename);
  std::filebuf *pbuff = fin.rdbuf();
  std::size_t size = pbuff->pubseekoff(0, fin.end, fin.in);
  pbuff->pubseekpos(0, fin.in);
  char *buffer = new char[size];

  pbuff->sgetn(buffer, size);
  fin.close();
  return buffer;
}

TEST(testZenroom_exec_tobuf, encrypt) {
  char *outBuf = new char[MAX_STRING];
  char *errBuff = new char[MAX_STRING];
  char *data = (char *)"secret";
  int r = zenroom_exec_tobuf(Readfile("scripts/encrypt.lua"), NULL, NULL, data,
                             1, outBuf, MAX_STRING, errBuff, MAX_STRING);
  EXPECT_EQ(0, r);
  ASSERT_STREQ(data, outBuf);
}

TEST(testZenroom_exec_tobuf, return_string) {
  char *outBuf = new char[MAX_STRING];
  char *errBuf = new char[MAX_STRING];
  int r = zenroom_exec_tobuf(Readfile("scripts/hello.lua"), NULL, NULL, NULL, 1,
                             outBuf, MAX_STRING, errBuf, MAX_STRING);
  EXPECT_EQ(0, r);
  ASSERT_STREQ("hello", outBuf);
}

int main(int argc, char *argv[]) {
  /*
  char *script = Readfile("scripts/hello.lua");
  char *data = (char *)"{\"val\":1}";
  char *keys = Readfile("keys/device_keys.json");
  char *stdoutBuff = new char[1024];
  char *stderrBuff = new char[1024];


  int r zenroom_exec(script, NULL, keys, data, 1);

  int r = zenroom_exec_tobuf(script, NULL, keys, data, 1, stdoutBuff, 1024,
                             stderrBuff, 1024);
  if (r == 0) {
    std::cout << "got:" << stdoutBuff << std::endl;
    std::cout << "len:" << strlen(stdoutBuff) << std::endl;
  } else {
    std::cout << "error:" << stderrBuff << std::endl;
  }
  */

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
