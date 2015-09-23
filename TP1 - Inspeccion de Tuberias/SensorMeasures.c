//
//  SensorMeasures.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 19/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>

#include "SensorMeasures.h"

static int const kMeasureSize = 2;

void sensorMeasuresCreate(SensorMeasures *sensor,
		Arguments *arguments,
		int estimateCount) {
	sensor->arguments = arguments;
	sensor->estimateMeasures = estimateCount;
	sensor->corrosionMeasuresCount = 0;
	sensor->firstCorrosionMeasure = 0;
	sensor->measuresRead = 0;
}

void sensorMeasuresDestroy(SensorMeasures *sensor) {
}

void sensorMeasuresReadMeasure(SensorMeasures *sensor, File *file) {
//	char *intToRead = (char *)malloc(kMeasureSize);
}
