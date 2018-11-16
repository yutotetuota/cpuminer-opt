#ifndef LYRA2REVC0BAN_GATE_H__
#define LYRA2REVC0BAN_GATE_H__ 1

#include "algo-gate-api.h"
#include <stdint.h>
#include "lyra2.h"

#if defined(__AVX2__)
  #define LYRA2REVc0ban_4WAY
#endif

extern __thread uint64_t* l2vc0ban_wholeMatrix;

bool register_lyra2revc0ban_algo( algo_gate_t* gate );

#if defined(LYRA2REVc0ban_4WAY)

void lyra2revc0ban_4way_hash( void *state, const void *input );

int scanhash_lyra2revc0ban_4way( int thr_id, struct work *work, uint32_t max_nonce,
                         uint64_t *hashes_done );

bool init_lyra2revc0ban_4way_ctx();

#endif

void lyra2revc0ban_hash( void *state, const void *input );

int scanhash_lyra2revc0ban( int thr_id, struct work *work, uint32_t max_nonce,
                    uint64_t *hashes_done );

bool init_lyra2revc0ban_ctx();

#endif

