#ifndef cspydr_chunk_h
#define cspydr_chunk_h

#include "common.h"
#include "value.h"

typedef enum
{
	OP_NEGATE,
	OP_PRINT,
	OP_JUMP_IF_FALSE,
	OP_JUMP,
	OP_LOOP,
	OP_CALL,
	OP_CLOSURE,
	OP_ADD,
	OP_SUBTRACT,
	OP_MULTIPLY,
	OP_DIVIDE,
	OP_POWER,
	OP_MODULO,
	OP_SHIFT_LEFT,
	OP_SHIFT_RIGHT,
	OP_RETURN,
	OP_NIL,
	OP_TRUE,
	OP_FALSE,
	OP_POP,
	OP_DEFINE_GLOBAL,
	OP_DEFINE_CONSTANT,
	OP_GET_GLOBAL,
	OP_SET_GLOBAL,
	OP_GET_UPVALUE,
	OP_SET_UPVALUE,
	OP_CLOSE_UPVALUE,
	OP_GET_LOCAL,
	OP_SET_LOCAL,
	OP_EQUAL,
	OP_GREATER,
	OP_LESS,
	OP_NOT,
	OP_CONSTANT,
	OP_EXIT,
} OpCode;

typedef struct
{
	int count;
	int capacity;
	uint8_t *code;
	int *lines;
	ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
int addConstant(Chunk *chunk, Value value);

#endif