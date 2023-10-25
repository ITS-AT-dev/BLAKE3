#include "blake3.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  // Initialize the hasher.
  blake3_hasher hasher;
  
  printf("starting...\n");
  const unsigned char oper_key[] = "OPER"; 
  const unsigned char admin_key[] = "ENERGY"; 
  const unsigned char super_key[] = "ITS"; 
  uint8_t output[BLAKE3_OUT_LEN];

  printf("OPER:\n");
  blake3_hasher_init(&hasher);
  blake3_hasher_update(&hasher, oper_key, 4);
  blake3_hasher_finalize(&hasher, output, BLAKE3_OUT_LEN);
    // Print the hash as hexadecimal.
  for (size_t i = 0; i < BLAKE3_OUT_LEN; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");

  printf("ADMIN:\n");
  blake3_hasher_init(&hasher);
  blake3_hasher_update(&hasher, admin_key, 6);
  blake3_hasher_finalize(&hasher, output, BLAKE3_OUT_LEN);
    // Print the hash as hexadecimal.
  for (size_t i = 0; i < BLAKE3_OUT_LEN; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");

   printf("SUPER:\n");
  blake3_hasher_init(&hasher);
  blake3_hasher_update(&hasher, super_key, 3);
  blake3_hasher_finalize(&hasher, output, BLAKE3_OUT_LEN);
    // Print the hash as hexadecimal.
  for (size_t i = 0; i < BLAKE3_OUT_LEN; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");   

  /* Output
  starting...
  OPER:
  996c20ed6c711fd86159fc5462f59566861670c43f0892e8d709f438b81c30ec
  ADMIN:
  8eda1200926ca62a7bc868ff093ff11d2db4311da162da95916748d02211f30c
  SUPER:
  97c2dd82ce739dbf6e66d60d9db6a642e29080ec19adea582b4c35752adcf31e
  
  */
  return 0;
}