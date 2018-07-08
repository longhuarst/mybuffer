#ifndef __ringbuffer_h
#define __ringbuffer_h

#include <stdint.h>
#include <stdbool.h>


#define ringbuffer_size (100)

typedef struct {
	uint8_t buffer[ringbuffer_size];
	uint32_t read_index;
	uint32_t write_index;
}ringbuffer_type;





void ringbuffer_init(ringbuffer_type *rb);
bool ringbuffer_is_empty(ringbuffer_type *rb);
bool ringbuffer_is_full(ringbuffer_type *rb);
void ringbuffer_push_back(ringbuffer_type *rb, uint8_t data);
uint8_t ringbuffer_pop_front(ringbuffer_type *rb);


#endif

