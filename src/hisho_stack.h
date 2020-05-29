/**
 * A rudimentary storage allocator that uses a LIFO queue (stack) to manage
 * memory.
 * Free calls must be made in opposite order to the alloc calls.
 * Memory is fixed in size and stored in a static variable (data segment of
 * virtual address space of program).
 *
 * Written with the help of "K&R: The C Programming Language. 2nd Edition:
 * Chapter 5.4".
 */

#pragma once

#include <stdio.h>

#define DEBUG_HISHO_STACK 0

#define ALLOC_BUFFER_SIZE 12

static char alloc_buffer[ALLOC_BUFFER_SIZE];
static char *alloc_next = alloc_buffer;

/**
 * Allocate a certain number of characters.
 * @param n number of characters to allocate.
 * @return pointer to n characters in storage.
 */
char *hisho_stack__alloc(int n);

/**
 * Free previously allocated storage space pointed to by p.
 * @param p pointer to start of storage space to free.
 */
void hisho_stack__free(char *p);

/**
 * Print characters of the entire buffer and show where next is pointing with a
 * ^ char. Line of characters will be wrapped with square brackets.
 * Example output:
 * [hello  ]
 * [     ^ ]
 * Used for debugging.
 */
void hisho_stack__print();