#include "DLLMain.h"

INT32 BuySkillCele(INT32 ClientID)
{
	// retornar 0 caso n�o queira utilizar a fun��o.
	// retornar 1 caso queira utilizar a fun��o.
	st_Mob *player = GetMobFromIndex(ClientID);

	if(player->Equip[0].EFV2 >= CELESTIAL)
		return 1;

	return 0;
}