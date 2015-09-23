//
//  SensorMeasures.h
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 19/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef SENSORMEASURES_H_
#define SENSORMEASURES_H_

#include "Arguments.h"
#include "File.h"

typedef struct {
	Arguments *arguments;
	int estimateMeasures;
	int corrosionMeasuresCount;
	int firstCorrosionMeasure;
	int measuresRead;
} SensorMeasures;

void sensorMeasuresCreate(SensorMeasures *sensor,
		Arguments *arguments,
		int estimateCount);

void sensorMeasuresDestroy(SensorMeasures *sensor);

void sensorMeasuresReadMeasure(SensorMeasures *sensor, File *file);

#endif /* SENSORMEASURES_H_ */
