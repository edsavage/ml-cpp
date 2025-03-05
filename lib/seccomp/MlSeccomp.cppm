module;
// WARNING: Detected unhandled non interesting includes.
// It is not suggested mix includes and imports from the compiler's
// perspective. Since it may introduce redeclarations within different
// translation units and the compiler is not able to handle such patterns
// efficiently.
//
// See https://clang.llvm.org/docs/StandardCPlusPlusModules.html#performance-tips
#include <core/CNonInstantiatable.h>

export module seccomp;
import std;
#define LIB_SECCOMP_USE_MODULES
export extern "C++" {
  #include "include/seccomp/CSystemCallFilter.h"
}
