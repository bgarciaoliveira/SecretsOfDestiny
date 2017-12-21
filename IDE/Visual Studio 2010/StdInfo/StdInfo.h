#include <Windows.h>

#ifndef _INCLUDE_STRUCTS_H_
#define _INCLUDE_STRUCTS_H_

struct st_Item
{
	WORD Index;
	struct{
		BYTE Index;
		BYTE Value;
	}Effect[3];
};

struct st_Position 
{
	WORD X;
	WORD Y;
};

typedef struct
{
	BYTE Index;
	BYTE Master;

	WORD Value;
	DWORD Time;
} st_Affect;

typedef struct
{
	WORD Level;
	unsigned short  Defense;
	unsigned short  Attack;

    struct  {
		BYTE Merchant : 4;
		BYTE Direction : 4;
	} Merchant;
	struct {
		BYTE Speed : 4;
		BYTE ChaosRate : 4;
	} Move; 

	unsigned short  maxHP, maxMP;
	unsigned short  curHP, curMP;

	unsigned short STR, INT;
	unsigned short  DEX, CON;

	BYTE Mastery[4];
} st_Status;

typedef struct
{
	char Name[16];
    char CapeInfo;

    struct
    {
        BYTE Merchant : 6;
        BYTE CityID : 2;
    } Info;

    WORD GuildIndex;
    BYTE ClassInfo;

	struct
    {
        BYTE SlowMov : 1;
        BYTE DrainHP : 1;
        BYTE VisionDrop : 1;
        BYTE Evasion : 1;
        BYTE Snoop : 1;
        BYTE SpeedMov : 1;
        BYTE SkillDelay : 1;
        BYTE Resist : 1;
    } AffectInfo;

    WORD QuestInfo;

    int Gold;
	unsigned int Exp;

    st_Position Last;
    st_Status bStatus;
    st_Status Status;

    st_Item Equip[16];
    st_Item Inventory[64];

    DWORD Learn;
    WORD StatusPoint;
    WORD MasterPoint;
    WORD SkillPoint;

    BYTE Critical;
    BYTE SaveMana;

    char SkillBar1[4];
    char GuildMemberType;

    BYTE MagicIncrement;
    BYTE RegenHP;
    BYTE RegenMP;

	struct
	{
		BYTE Fogo;
		BYTE Gelo;
		BYTE Sagrado;
		BYTE Trovao;
	} Resist;

	char SkillBar2[16];

	st_Affect Affect[16];
		
	UINT32 ClassMaster;
	UINT32 Face;
	int Hold;

} stCharacter;

typedef struct
{
	char Name[16];
    char CapeInfo;

    struct
    {
        BYTE Merchant : 6;
        BYTE CityID : 2;
    } Info;

    WORD GuildIndex;
    BYTE ClassInfo;

	struct
    {
        BYTE SlowMov : 1;
        BYTE DrainHP : 1;
        BYTE VisionDrop : 1;
        BYTE Evasion : 1;
        BYTE Snoop : 1;
        BYTE SpeedMov : 1;
        BYTE SkillDelay : 1;
        BYTE Resist : 1;
    } AffectInfo;

    WORD QuestInfo;

    int Gold;
	unsigned int Exp;

    st_Position Last;
    st_Status bStatus;
    st_Status Status;

    st_Item Equip[16];
    st_Item Inventory[64];

    DWORD Learn;
    WORD StatusPoint;
    WORD MasterPoint;
    WORD SkillPoint;

    BYTE Critical;
    BYTE SaveMana;

    char SkillBar1[4];
    char GuildMemberType;

    BYTE MagicIncrement;
    BYTE RegenHP;
    BYTE RegenMP;

	struct
	{
		BYTE Fogo;
		BYTE Gelo;
		BYTE Sagrado;
		BYTE Trovao;
	} Resist;
	
	char SkillBar2[16];

	st_Affect Affect[16];
		
	UINT32 ClassMaster;
	UINT32 Face;
	int Hold;

	struct
	{
	} Game;
} stMOB;

typedef struct {
	// Login do usu�rio citado
	char Login[16];
	// Senha do usu�rio citado
	char Senha[16];
	// Num�rica do usu�rio
	char Numerica[6];
	// Dia/mes/ano/hora/minuto 
	// Utilizado em caso de banimento para sua checagem
	BYTE Ban[5];
	// Quantia de cash do usu�rio
	DWORD Cash;
	// Quantia de gold no banco do usu�rio
	DWORD StorageCoin;
	// Itens do banco do usu�rio
	st_Item ItensStorage[128];		
	// Os 4 personagens da conta est�o guardados aqui
	stCharacter Char[4];
	// AcessLevel da conta
	UINT32 AcessLevel;
} stAccount;

typedef struct
{
	stAccount cAccount;
	struct 
	{
		// Status dele -> Onde est� e o que est� fazendo
		WORD Status;
		// Socket do usu�rio
		DWORD Socket;
		// Seu IP
		char IPAddress[16];
		// ClientID
		WORD ClientID;
		// Timer do �ltimo save account
		INT64 LastSave;
		// Em qual personagem ele conectou
		BYTE Connected;
		// Cada usu�rio possui seu pr�prio buffer
		BYTE Buffer[65535];
		// Cada usu�rio possui um buffer send
		BYTE sendBuffer[65535];
		// Size atual do buffer
		UINT32 SizeOfData;
	} Game;
} CUser;

#endif