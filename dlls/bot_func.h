//
// HPB_bot - botman's High Ping Bastard bot
//
// (http://planethalflife.com/botman/)
//
// bot_func.h
//

#ifndef BOT_FUNC_H
#define BOT_FUNC_H

//prototypes of bot functions...

void BotSpawnInit( bot_t *pBot );
void BotCreate( edict_t *pPlayer, const char *arg1, const char *arg2, const char *arg3, const char *arg4 );
void BotFindItem( bot_t *pBot );
void BotThink( bot_t *pBot );


float BotChangePitch( bot_t *pBot, float speed );
void BotFixIdealYaw( edict_t *pEdict );
float BotChangeYaw( bot_t *pBot, float speed );
void BotFixBodyAngles(edict_t *pEdict);
void BotFixViewAngles(edict_t *pEdict);
bool BotFindWaypoint( bot_t *pBot );
bool BotHeadTowardWaypoint( bot_t *pBot );
void BotOnLadder( bot_t *pBot, float moved_distance );
void BotUnderWater( bot_t *pBot );
void BotUseLift( bot_t *pBot, float moved_distance );
bool BotStuckInCorner( bot_t *pBot );
void BotTurnAtWall( bot_t *pBot, TraceResult *tr );
bool BotCantMoveForward( bot_t *pBot, TraceResult *tr );
bool BotCanJumpUp( bot_t *pBot );
bool BotCanDuckUnder( bot_t *pBot );
void BotRandomTurn( bot_t *pBot );
bool BotFollowUser( bot_t *pBot );
bool BotCheckWallOnLeft( bot_t *pBot );
bool BotCheckWallOnRight( bot_t *pBot );
void BotUseDoor( bot_t *pBot );

edict_t *BotFindEnemy( bot_t *pBot );
bool BotFireWeapon( const Vector& v_enemy, bot_t *pBot, int weapon_choice);
void BotShootAtEnemy( bot_t *pBot );
bool BotShootTripmine( bot_t *pBot );

#endif // BOT_FUNC_H

