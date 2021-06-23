#ifndef INC_SECURITYELEMENTS_H_
#define INC_SECURITYELEMENTS_H_

#include "main.h"

typedef struct {
	int APPS, BPPC;
} errors_t;

void turnOff();
void startProtocol();

void APPS_Check(uint32_t *APPS_Data);
void BPPC_Check(uint32_t APPS, uint32_t BSE);



#endif /* INC_SECURITYELEMENTS_H_ */
