#ifndef _STUB_ENGINE_H_
#define _STUB_ENGINE_H_

#include <cstring>
#include <cctype>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "extdll.h"
#include "enginecallback.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::vector;

namespace foolsgoldsource
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		const enginefuncs_t GetServerEngineFunctions();
		const globalvars_t GetServerGlobalVariables();

		const string GetGameDirectory();
		void SetGameDirectory( const string& strGameDir );
		bool GetIsDedicatedServer();
		void SetIsDedicatedServer( const bool bIsDedicatedServer );
		bool GetIsCareerMatch();
		void SetIsCareerMatch( const bool bIsCareerMatch);

		void SetMaxClients( const int iMaxClients );

		// below shouldn't be public because the game doesn't have access to them

		// TODO: below be in some server struct?
		vector<shared_ptr<edict_t>> edicts;
		vector<string> models;
		vector<string> sounds;
		int iMaxEdicts;

		// TODO: how does the engine track this?
		unsigned int iStringTableOffset;

		const static unsigned int iStringTableSize = 2048;
	private:
		enginefuncs_t engineFunctions;
		globalvars_t globalVariables;

		string strGameDir;

		bool bIsDedicatedServer;
		bool bIsCareerMatch;
	};

	class Util
	{
	public:
		static string tolowercase( const string& str );
	};

	extern Engine gEngine;

	int pfnPrecacheModel( char* s );
	int pfnPrecacheSound( char* s );
	void pfnSetModel( edict_t* e, const char* m );
	int pfnModelIndex( const char* m );

	void pfnSetSize( edict_t* e, const float* rgflMin, const float* rgflMax );

	void pfnAlertMessage( ALERT_TYPE atype, char *szFmt, ... );

	int pfnAllocString( const char* szValue );

	edict_t* pfnPEntityOfEntOffset( int iEntOffset );

	edict_t* pfnPEntityOfEntIndex( int iEntIndex );

	void pfnGetGameDir( char *szGetGameDir );

	int pfnIsDedicatedServer( void );

	int pfnIsCareerMatch( void );

	edict_t* pfnPEntityOfEntIndexAllEntities( int iEntIndex );
}

#endif // _STUB_ENGINE_H_