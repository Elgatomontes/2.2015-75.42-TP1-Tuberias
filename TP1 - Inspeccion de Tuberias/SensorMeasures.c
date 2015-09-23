//
//  SensorMeasures.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 19/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "HexFormatHelper.h"
#include "SensorMeasures.h"

static int const kMeasureSize = 2;

void processValue(int measureValue) {
}

void sensorMeasuresCreate(SensorMeasures *sensor,
		Arguments *arguments,
		int estimateCount) {
	sensor->arguments = arguments;
	sensor->estimateMeasures = estimateCount;
	sensor->corrosionMeasuresCount = 0;
	sensor->firstCorrosionMeasure = 0;
	sensor->measuresRead = 0;
	printf("Se creó un SensorMeasures\n");
}

void sensorMeasuresDestroy(SensorMeasures *sensor) {
}

void sensorMeasuresReadMeasure(SensorMeasures *sensor, File *file) {
	short int *bytesToRead = (short int *)malloc(sizeof(kMeasureSize));
//	fileRead(file, bytesToRead, kMeasureSize);
	fileReadShortInt(file, *bytesToRead);

	if (fileEndOfFile(file) != EOF) {
		sensor->measuresRead++;
//		unsigned long int measureValue = formatHexToInt2Bytes(bytesToRead);
//		printf("Valor de la medición %d: %li\n",
//		sensor->measuresRead, measureValue);
		printf("Lo que se leyó en seco %d: %i\n",
				sensor->measuresRead, *bytesToRead);
	}

	free(bytesToRead);
}
