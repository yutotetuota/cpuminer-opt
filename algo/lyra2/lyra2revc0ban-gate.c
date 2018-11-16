#include "lyra2revc0ban-gate.h"

__thread uint64_t* l2c0ban2_wholeMatrix;

void lyra2revc0ban_set_target( struct work* work, double job_diff )
{
 work_set_target( work, job_diff / (256.0 * opt_diff_factor) );
}

bool lyra2revc0ban_thread_init()
{
   const int64_t ROW_LEN_INT64 = BLOCK_LEN_INT64 * 4; // nCols
   const int64_t ROW_LEN_BYTES = ROW_LEN_INT64 * 8;

   int i = (int64_t)ROW_LEN_BYTES * 4; // nRows;
   l2v2_wholeMatrix = _mm_malloc( i, 64 );
#if defined (LYRA2REVc0ban_4WAY)
   init_lyra2revc0ban_4way_ctx();;
#else
   init_lyra2revc0ban_ctx();
#endif
   return l2vc0ban_wholeMatrix;
}

bool register_lyra2revc0ban_algo( algo_gate_t* gate )
{
#if defined (LYRA2REVc0ban_4WAY)
  gate->scanhash  = (void*)&scanhash_lyra2revc0ban_4way;
  gate->hash      = (void*)&lyra2revc0ban_4way_hash;
#else
  gate->scanhash  = (void*)&scanhash_lyra2revc0ban;
  gate->hash      = (void*)&lyra2revc0ban_hash;
#endif
  gate->optimizations = SSE2_OPT | AES_OPT | SSE42_OPT | AVX2_OPT;
  gate->miner_thread_init = (void*)&lyra2revc0ban_thread_init;
  gate->set_target        = (void*)&lyra2revc0ban_set_target;
  return true;
};


