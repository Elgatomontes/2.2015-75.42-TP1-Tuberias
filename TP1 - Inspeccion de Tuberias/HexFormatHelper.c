//
//  HexFormatHelper.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 20/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#include "HexFormatHelper.h"

int formatHexToInt(char *hexNumber) {
	int firstHex = hexNumber[0] * pow(2, 24);
	int secondHex = hexNumber[1] * pow(2, 16);
	int thirdHex = hexNumber[2] * pow(2, 8);
	int fourthHex = hexNumber[3] * pow(2, 0);

	return firstHex + secondHex + thirdHex + fourthHex;
}

