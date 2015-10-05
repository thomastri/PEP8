#include <stdio.h>              /* standard I/O */
#include <stdbool.h>            /* bool types */
#include <stdint.h>             /* uint32_t, uint8_t, and similar types */
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "../cmdline/parse.h"   /* command line parser */

int disasm(uint8_t *dynamic_array, uint32_t bytes_in_file)
{
	uint32_t array_iter = 0;
	uint32_t addr = 0;

	char adr = NULL;
	char reg = NULL;
	//format for column headers
	printf("Addr\tCode\tSymbol\tMnemon\tOperand\n");

	for (array_iter = 0; array_iter < bytes_in_file; array_iter++)
	//for (array_iter = 0; array_iter < 11; array_iter++)
	{

		//if first half equals 0
		if ((dynamic_array[array_iter] & 0xF0) == 0x00)
		{
			//STOP
			if ((dynamic_array[array_iter] & 0x0F) == 0x00)
			{
				printf("%04X\t%02X\t\tSTOP\n", addr, dynamic_array[array_iter]);

				//unary iteration
				addr = addr + 1;
				//break; //stop program
			}

			//RETTR
			if ((dynamic_array[array_iter] & 0x0F) == 0x01)
			{
				printf("%04X\t%02X\t\tRETTR\n", addr,
						dynamic_array[array_iter]);

				//unary iteration
				addr = addr + 1;
			}

			//MOVSPA
			if ((dynamic_array[array_iter] & 0x0F) == 0x02)
			{
				printf("%04X\t%02X\t\tMOVSPA\n", addr,
						dynamic_array[array_iter]);

				//unary iteration
				addr = addr + 1;
			}

			//MOVFLGA
			if ((dynamic_array[array_iter] & 0x0F) == 0x03)
			{
				printf("%04X\t%02X\t\tMOVFLGA\n", addr,
						dynamic_array[array_iter]);

				//unary iteration
				addr = addr + 1;
			}

			//0x0E
			//BR
			if ((dynamic_array[array_iter] & 0x0E) == 0x04)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBR\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBR\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}

			//BRLE
			if ((dynamic_array[array_iter] & 0x0E) == 0x06)
			{

				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBRLE\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBRLE\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;

			}

			//BRLT
			if ((dynamic_array[array_iter] & 0x0E) == 0x08)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBRLT\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBRLT\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}

			//BREQ
			if ((dynamic_array[array_iter] & 0x0E) == 0x0A)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBREQ\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBREQ\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}

			//BRNE
			if ((dynamic_array[array_iter] & 0x0E) == 0x0C)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBRNE\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBRNE\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;

			}

			//BRGE
			if ((dynamic_array[array_iter] & 0x0E) == 0x0E)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBRGE\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBRGE\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}
		}

		//if first half == 0x10
		if ((dynamic_array[array_iter] & 0xF0) == 0x10)
		{
			//BRGT
			if ((dynamic_array[array_iter] & 0x0E) == 0x00)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBRGT\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBRGT\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}

			//BRV
			if ((dynamic_array[array_iter] & 0x0E) == 0x02)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBRV\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBRV\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}

			//BRC
			if ((dynamic_array[array_iter] & 0x0E) == 0x04)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tBRC\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tBRC\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}

			//CALL
			if ((dynamic_array[array_iter] & 0x0E) == 0x06)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tCALL\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tCALL\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				addr = addr + 3;
				array_iter = array_iter + 2;
			}

			//NOTr
			if ((dynamic_array[array_iter] & 0x0E) == 0x08)
			{
				//register check: accumulator
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					reg = 'A';
					printf("%04X\t%02X%02X%02X\t\tNOTA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					reg = 'X';
					printf("%04X\t%02X%02X%02X\t\tNOTX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//unary iteration
				addr = addr + 1;
			}

			//NEGr
			if ((dynamic_array[array_iter] & 0x0E) == 0x0A)
			{
				//register check: accumulator
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					reg = 'A';
					printf("%04X\t%02X%02X%02X\t\tNEGA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					reg = 'X';
					printf("%04X\t%02X%02X%02X\t\tNEGX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//unary iteration
				addr = addr + 1;
			}

			//ASLr
			if ((dynamic_array[array_iter] & 0x0E) == 0x0C)
			{
				//register check: accumulator
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					reg = 'A';
					printf("%04X\t%02X%02X%02X\t\tASLA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					reg = 'X';
					printf("%04X\t%02X%02X%02X\t\tASLX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//unary iteration
				addr = addr + 1;
			}

			//ASRr
			if ((dynamic_array[array_iter] & 0x0E) == 0x0E)
			{
				//register check: accumulator
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					reg = 'A';
					printf("%04X\t%02X%02X%02X\t\tASRA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					reg = 'X';
					printf("%04X\t%02X%02X%02X\t\tASRX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//unary iteration
				addr = addr + 1;
			}
		}

		//if first half == 0x20
		if ((dynamic_array[array_iter] & 0xF0) == 0x20)
		{
			//ROLr
			if ((dynamic_array[array_iter] & 0x0E) == 0x00)
			{
				//register check: accumulator
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					reg = 'A';
					printf("%04X\t%02X%02X%02X\t\tROLA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					reg = 'X';
					printf("%04X\t%02X%02X%02X\t\tROLX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//unary iteration
				addr = addr + 1;
			}

			//RORr
			if ((dynamic_array[array_iter] & 0x0E) == 0x02)
			{
				//register check: accumulator
				if ((dynamic_array[array_iter] & 0x01) == 0x00)
				{
					reg = 'A';
					printf("%04X\t%02X%02X%02X\t\tRORA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					reg = 'X';
					printf("%04X\t%02X%02X%02X\t\tRORX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter], reg);
				}

				//unary iteration
				addr = addr + 1;
			}

			//NOPn
			if ((dynamic_array[array_iter] & 0x0C) == 0x04)
			{
				//register check: accumulator
				if ((dynamic_array[array_iter] & 0x0C) == 0x04)
				{
					adr = 'n';
					printf("%04X\t%02X%02X%02X\t\tNOPn\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x0C) == 0x01)
				{
					reg = 'n';
					printf("%04X\t%02X%02X%02X\t\tNOPn\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//unary iteration
				addr = addr + 1;
			}

			//NOP
			if ((dynamic_array[array_iter] & 0x08) == 0x08)
			{
				//address check: immediate
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tNOP\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//register check: index register
				else if ((dynamic_array[array_iter] & 0x01) == 0x01)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tNOP\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//non-unary iteration
				array_iter = array_iter + 2;
				addr = addr + 3;
			}
		}

		//DECI && DECO
		if ((dynamic_array[array_iter] & 0xF0) == 0x30)
		{
			//DECI
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tDECI\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: indexed
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'x';
					printf("%04X\t%02X%02X%02X\t\tDECI\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//DECO
			if ((dynamic_array[array_iter] & 0x08) == 0x08)
			{
				//addressing check: immediate
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tDECO\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: direct
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tDECO\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non-unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//STRO && CHARI
		if ((dynamic_array[array_iter] & 0xF0) == 0x40)
		{
			//STRO
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//addressing check: direct
				if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSTRO\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: else
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = '?';
					printf("%04X\t%02X%02X%02X\t\tSTRO\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//CHARI
			if ((dynamic_array[array_iter] & 0x08) == 0x08)
			{
				//addressing check: direct
				if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tCHARI\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//addressing check: else
				else if ((dynamic_array[array_iter] & 0x07) != 0x01)
				{
					adr = '?';
					printf("%04X\t%02X%02X%02X\t\tCHARI\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}
			}

			//non-unary iteration
			addr = addr + 3;
			array_iter = array_iter + 2;
		}

		//CHARO && RETn
		if ((dynamic_array[array_iter] & 0xF0) == 0x50)
		{

			//CHARO
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{

				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tCHARO\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else //if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{

					adr = 'd';

					printf("%04X\t%02X%02X%02X\t\tCHARO\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}
				//non unary iteration
				array_iter = array_iter + 2;
				addr = addr + 3;
			}

			//RETn
			if ((dynamic_array[array_iter] & 0x08) == 0x08)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'n';
					printf("%04X\t%02X%02X%02X\t\tRETn\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}
				//non unary iteration
				addr = addr + 1;
			}
		}

		//ADDSP && SUBSP
		if ((dynamic_array[array_iter] & 0xF0) == 0x60)
		{
			//ADDSP
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tADDSP\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tADDSP\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//SUBSP
			if ((dynamic_array[array_iter] & 0x08) == 0x08)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tSUBSP\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSUBSP\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;

		}

		//ADDr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0x70)
		{
			//ADDA
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tADDA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tADDA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//ADDX
			if ((dynamic_array[array_iter] & 0x08) == 0x08)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tADDX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tADDX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//SUBr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0x80)
		{
			//register check: Accumulator (SUBA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tSUBA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSUBA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//register check: index register (SUBX)
			if ((dynamic_array[array_iter] & 0x08) == 0x08)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tSUBX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSUBX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non-unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//ANDr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0x90)
		{
			//register check: Accumulator (ANDA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tANDA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tANDA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//register check: index register (ANDX)
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tANDX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tANDX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non-unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//ORr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0xA0)
		{

			//ORA
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tORA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tORA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//ORX
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tORX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tORX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//CPr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0xB0)
		{
			//register check: Accumulator (CPA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tCPA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tCPA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//register check: index register (CPX)
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tCPX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tCPX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non-unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//LDr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0xC0)
		{

			//LDA
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tLDA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tLDA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//LDX
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tLDX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tLDX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//LDBYTEr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0xD0)
		{
			//register check: Accumulator (LDBYTEA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tLDBYTEA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tLDBYTEA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//register check: index register (LDBYTEX)
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tLDBYTEX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tLDBYTEX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non-unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

		//STr INSTRUCTION
		if ((dynamic_array[array_iter] & 0xF0) == 0xE0)
		{
			//register check: Accumulator (STA)
			if ((dynamic_array[array_iter] & 0x08) == 0x00)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tSTA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSTA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//register check: index register (STX)
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tSTX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSTX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non-unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
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
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tSTBYTEA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSTBYTEA\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}

			//STBYTEX
			if ((dynamic_array[array_iter] & 0x08) == 0x01)
			{
				//immediate adr check
				if ((dynamic_array[array_iter] & 0x07) == 0x00)
				{
					adr = 'i';
					printf("%04X\t%02X%02X%02X\t\tSTBYTEX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

				//direct adr check
				else if ((dynamic_array[array_iter] & 0x07) == 0x01)
				{
					adr = 'd';
					printf("%04X\t%02X%02X%02X\t\tSTBYTEX\t0x%04X,%c\n", addr,
							dynamic_array[array_iter],
							dynamic_array[array_iter + 1],
							dynamic_array[array_iter + 2],
							dynamic_array[array_iter + 2], adr);
				}

			}
			//non unary iteration
			array_iter = array_iter + 2;
			addr = addr + 3;
		}

	} //END FOR LOOP
	return 0;
}
