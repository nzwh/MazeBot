#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cfloat>
#include <tuple>
#include <queue>
#include <stack>
#include <chrono>
#include <thread>

using namespace std;

#define LBLK  "\x1B[30;1m"
#define LRED  "\x1B[31;1m"
#define LGRN  "\x1B[32;1m"
#define LYEL  "\x1B[33;1m"
#define LBLU  "\x1B[34;1m"
#define LMAG  "\x1B[35;1m"
#define LCYN  "\x1B[36;1m"
#define LWHT  "\x1B[37;1m"

#define KBLK  "\x1B[30m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define HBLD  "\x1B[1m"
#define HUND  "\x1B[4m"
#define HRVS  "\x1B[7m"

#define KRST  "\x1B[0m"

#define NCUL "\u250c"
#define NCUR "\u2510"
#define NCDL "\u2514"
#define NCDR "\u2518"
#define NHFT "\u2500"
#define NVFT "\u2502"
#define NBML "\u2524"
#define NBMR "\u251c"
#define NBMU "\u252c"
#define NBMD "\u2534"
#define NALL "\u253c"

#define FSCND 999999
#define HSCND 500000
#define MSCND 100000
#define NSCND 50000

#define CAP 120

#include "logic/structs.hpp"
#include "logic/helpers.hpp"
#include "interface/gui.hpp"
#include "logic/backend.hpp"

