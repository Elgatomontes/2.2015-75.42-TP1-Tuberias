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
	char *bytesToRead = (char *)malloc(kMeasureSize);
	fileRead(file, bytesToRead, kMeasureSize);

	if (fileEndOfFile(file) != EOF) {
		sensor->measuresRead++;
		printf("Mediciones leídas: %d\n", sensor->measuresRead);
		//		int measureValue = formatHexToInt(bytesToRead);
	}

	free(bytesToRead);
}
