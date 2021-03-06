/*

  ftpack - typedef'd data type and associated functions to
  manipulate and read packets used by nu-ft

  note that:
    ftpack_create calls malloc()  internally to  perform  allocation
    and should set errno on failure

*/

#ifndef FTPACKET_H
#define FTPACKET_H

/* this seems to be needed for uint8_t on clang */
#include <stdlib.h>

typedef void ftpack;

#define FTPACKET_PSIZE(p) \
  ((*(ssize_t*)(p+sizeof(uint8_t)+sizeof(uint32_t)))+S(uint8_t)+S(uint32_t)+S(ssize_t)

#define FTPACK_DSIZE(p) (*(ssize_t*)(p+sizeof(uint8_t)+sizeof(uint32_t)))

#define FTPACK_PTYPE(p) (uint8_t)*((uint8_t*)p)

#define FTPACK_SNUM(p) (uint32_t)*((uint32_t*)(p+sizeof(uint8_t)))

#define FTPACK_PDATA(p) (p+sizeof(uint8_t)+sizeof(uint32_t)+sizeof(ssize_t))

#define FTPACK_FREE(p) free(p)

ftpack *ftpack_create(uint8_t type, uint32_t snum, void *data, ssize_t size);
ssize_t ftpack_psize(ftpack *packet);
ssize_t ftpack_dsize(ftpack *packet);
uint8_t ftpack_ptype(ftpack *packet);
void *ftpack_pdata(ftpack *packet);
void ftpack_free(ftpack *packet);

#endif
