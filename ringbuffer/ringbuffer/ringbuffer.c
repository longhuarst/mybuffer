#include "ringbuffer.h"


void ringbuffer_init(ringbuffer_type *rb)
{
	rb->read_index = 0;
	rb->write_index = 0;
}

bool ringbuffer_is_empty(ringbuffer_type *rb)
{
	return rb->write_index == rb->read_index;
}

bool ringbuffer_is_full(ringbuffer_type *rb)
{
	return (rb->write_index - rb->read_index + ringbuffer_size) % ringbuffer_size == (ringbuffer_size - 1);
}

void ringbuffer_push_back(ringbuffer_type *rb, uint8_t data)
{
	if (ringbuffer_is_full(rb)) {
		rb->read_index++;
		rb->read_index %= ringbuffer_size;
	}

	rb->buffer[rb->write_index] = data;
	rb->write_index++;
	rb->write_index %= ringbuffer_size;
}


uint8_t ringbuffer_pop_front(ringbuffer_type *rb)
{
	if (ringbuffer_is_empty(rb)) {
		return 0;
	}

	uint8_t res = rb->buffer[rb->read_index];

	rb->read_index++;
	rb->read_index %= ringbuffer_size;

	return res;
}

