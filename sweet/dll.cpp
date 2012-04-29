#include <win/application.hxx>
#include <cstdlib>
#include <iostream>
#include <nt/heap.hxx>

using namespace ntl;
using namespace ntl::nt;
#pragma comment(linker, "/entry:entry")

//////////////////////////////////////////////////////////////////////////
win::boolean __stdcall entry(pe::image* self, DllMainReason reason, const void*)
{
  if(reason == DllMainReason::DllProcessAttach){
    ntl::__init_crt(true);
  }else if(reason == DllMainReason::DllProcessDetach){
    ntl::__init_crt(false);
  }
  return true;
}

int NTL_CRTCALL printf(const char* format, ...)
{
  char buf[2048];
  va_list va;
  va_start(va, format);
  return std::vsnprintf(buf, _countof(buf), format, va);
}

static heap cheap(heap::growable|heap::zero_memory|heap::free_checking_enabled|heap::tail_checking_enabled, 1024*1024*10);

__noalias void NTL_CRTCALL free(void *ptr)
{
  cheap.free(ptr);
}

__noalias void* __restrict  NTL_CRTCALL malloc(size_t size)
{
  return cheap.alloc(size);
}

__noalias void* __restrict NTL_CRTCALL realloc(void *ptr, size_t size)
{
  return ptr ? cheap.realloc(ptr, size) : cheap.alloc(size);
}
