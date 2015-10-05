//Thomas Le

#include <stdio.h>              /* standard I/O */
#include <stdbool.h>            /* bool types */
#include <stdint.h>             /* uint32_t, uint8_t, and similar types */
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int interp(uint8_t *dynamic_array, uint32_t bytes_in_file)
{

	uint16_t accu = 0;
	uint16_t index = 0;
	uint16_t pc = 3;
	uint16_t op = 0;

	//default settings
	bool unary = false;
	bool output = false;
	bool str = false;

	int array_iter = 0;

	printf("----------------------------------------\n");
	for (array_iter = 0; array_iter < bytes_in_file; array_iter++)
	{

		uint16_t N = 0;
		uint16_t Z = 0;

		if (array_iter == 0)
		{
			if (((dynamic_array[0] & 0xF0) == 0x00)
					|| ((dynamic_array[array_iter] & 0x0E) == 0x08)
					|| ((dynamic_array[array_iter] & 0x0E) == 0x0A))
			{
				pc = 1;
			}
		}

		//PRINT STATEMENTS

		//store
		if (str)
		{
			printf("  Mem[%04x] <-- 0x%04x\n", op - 1, accu);
			printf("----------------------------------------\n");
			str = false;
		}

		//output
		if (output)
		{
			printf("  Output '%c'\n", accu);
			printf("----------------------------------------\n");
			output = false;
		}

		//STOP
		if (((dynamic_array[array_iter] & 0xF0) == 0x00)
				&& ((dynamic_array[array_iter] & 0x0F) == 0x00))
		{
			array_iter += 1;
			pc -= 3;

			//print one last time
			printf("Status bits (NZVC)\t\t0 0 0 0\n");
			printf("Accumulator (A)\t\t\t0x%04X\n", accu);
			printf("Index register (X)\t\t0x%04X\n", index);
			printf("Program counter (PC)\t\t0x%04X\n", pc);
			printf("Instruction Register (IR)\t0x000000\n");
			printf("----------------------------------------\n");

			break;
		}

		//non-unary op
		op = (dynamic_array[array_iter + 1] << 8)
				+ dynamic_array[array_iter + 2] + 1;

		printf("Status bits (NZVC)\t\t%d %d 0 0\n", N, Z);
		printf("Accumulator (A)\t\t\t0x%04X\n", accu);
		printf("Index register (X)\t\t0x%04X\n", index);
		printf("Program counter (PC)\t\t0x%04X\n", pc);
		printf("Instruction Register (IR)\t0x%02X%02X%02X\n",
				dynamic_array[array_iter], dynamic_array[array_iter + 1],
				dynamic_array[array_iter + 2]);
		printf("----------------------------------------\n");

		//OUTPUT
		if ((dynamic_array[array_iter] & 0xF0) == 0x50)
		{

			//CHARO
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{

				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{

				}

				//direct adr check
				else //if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					output = true;
				}

			}
		}

		//LOGIC OPERATIONS

		//ADDr
		if ((dynamic_array[array_iter] & 0xF0) == 0x70)
		{
			//ADDA
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					accu += op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					accu += dynamic_array[op];
				}

			}

			//ADDX
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					index += op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					index += dynamic_array[op];
				}

			}

		}

		//SUBr
		if (((dynamic_array[array_iter] & 0xF0) == 0x80))
		{
			//register check: Accumulator (SUBA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					accu -= op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					accu -= dynamic_array[op];
				}

			}

			//register check: index register (SUBX)
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					index -= op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					index -= dynamic_array[op];
				}

			}

		}

		//ANDr
		if (((dynamic_array[array_iter] & 0xF0) == 0x90))
		{
			//register check: Accumulator (ANDA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					accu = accu & op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					accu = accu & dynamic_array[op];
				}

			}

			//register check: index register (ANDX)
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					index = index & op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					index = index & dynamic_array[op];
				}

			}

		}

		//ORr
		if (((dynamic_array[array_iter] & 0xF0) == 0xA0))
		{
			//ORA
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					accu = accu | op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					accu = accu | dynamic_array[op];
				}

			}

			//ORX
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					index = index | op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					index = index | dynamic_array[op];
				}

			}

		}

		//CPr
		if (((dynamic_array[array_iter] & 0xF0) == 0xB0))
		{
			//register check: Accumulator (CPA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					if (accu < op)
					{
						N = 1;
						Z = 0;
					}

					if (accu == op)
					{
						N = 0;
						Z = 1;
					}

					if (accu > op)
					{
						N = 0;
						Z = 0;
					}
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					if (accu < dynamic_array[op])
					{
						N = 1;
						Z = 0;
					}

					if (accu == dynamic_array[op])
					{
						N = 0;
						Z = 1;
					}

					if (accu > dynamic_array[op])
					{
						N = 0;
						Z = 0;
					}
				}

			}

			//register check: index register (CPX)
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					if (index < op)
					{
						N = 1;
						Z = 0;
					}

					if (index == op)
					{
						N = 0;
						Z = 1;
					}

					if (index > op)
					{
						N = 0;
						Z = 0;
					}
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					if (index < dynamic_array[op])
					{
						N = 1;
						Z = 0;
					}

					if (index == dynamic_array[op])
					{
						N = 0;
						Z = 1;
					}

					if (index > dynamic_array[op])
					{
						N = 0;
						Z = 0;
					}
				}

			}

		}

		//NOTr + NEGr
		if ((dynamic_array[array_iter] & 0xF0) == 0x10)
		{
			unary = true;

			//NOTr
			if ((dynamic_array[array_iter] & 0x0E) == 0x08)
			{
				//NOTA
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					accu = ~accu;
				}

				//NOTX
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					index = ~index;
				}

			}

			//NEGr
			if ((dynamic_array[array_iter] & 0x0E) == 0x0A)
			{
				//NEGA
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					accu = ~accu + 1;
				}

				//NEGX
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					index = ~index + 1;
				}
			}
		}

		//LDr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0xC0)
		{
			//LDA
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{

				//LDA (Immediate)
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					accu = op;
				}

				//LDA (Direct)
				if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					accu = dynamic_array[op];
				}

			}

			//LDX
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					index = op;
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					index = dynamic_array[op];
				}

			}

		}

		//STBYTEr
		if ((dynamic_array[array_iter] & 0xF0) == 0xF0)
		{

			//STBYTEA
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{

				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					str = true;
				}

			}

			//STBYTEX
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{

				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{

				}

			}

		}

		//ADDITIONAL PRINT STATEMENTS

		if (unary)
		{
			array_iter += 1;
			pc += 1;
			unary = false;
		}

		else //non-unary
		{
			array_iter += 2;
			pc += 3;
		}

	} //END FOR LOOP
	return 0;

}
