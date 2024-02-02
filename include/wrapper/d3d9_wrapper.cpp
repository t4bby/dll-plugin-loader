#include "d3d9_module_manager.h"

extern "C" DWORD WINAPI Direct3DCreate9On12Ex(__int64 a1, __int64 a2, int a3, __int64 a4)
{
	return D3d9ModuleManager::Get().Direct3DCreate9On12Ex(a1, a2, a3, a4);
}

extern "C" DWORD WINAPI Direct3DShaderValidatorCreate9()
{
	return D3d9ModuleManager::Get().Direct3DShaderValidatorCreate9();
}

extern "C" DWORD WINAPI D3DPERF_BeginEvent(unsigned int a1, __int64 a2)
{
	return D3d9ModuleManager::Get().D3DPERF_BeginEvent(a1, a2);
}

extern "C" DWORD WINAPI D3DPERF_EndEvent()
{
	return D3d9ModuleManager::Get().D3DPERF_EndEvent();
}

extern "C" DWORD WINAPI D3DPERF_GetStatus()
{
	return D3d9ModuleManager::Get().D3DPERF_GetStatus();
}

extern "C" DWORD WINAPI D3DPERF_QueryRepeatFrame()
{
	return D3d9ModuleManager::Get().D3DPERF_QueryRepeatFrame();
}

extern "C" DWORD WINAPI D3DPERF_SetMarker(unsigned int a1, __int64 a2)
{
	return D3d9ModuleManager::Get().D3DPERF_SetMarker(a1, a2);
}

extern "C" DWORD WINAPI D3DPERF_SetOptions(unsigned int a1, __int64 a2)
{
	return D3d9ModuleManager::Get().D3DPERF_SetOptions(a1, a2);
}

extern "C" DWORD WINAPI D3DPERF_SetRegion(unsigned int a1, __int64 a2)
{
	return D3d9ModuleManager::Get().D3DPERF_SetRegion(a1, a2);
}

extern "C" DWORD WINAPI DebugSetLevel()
{
	return D3d9ModuleManager::Get().DebugSetLevel();
}

extern "C" DWORD WINAPI DebugSetMute()
{
	return D3d9ModuleManager::Get().DebugSetMute();
}

extern "C" DWORD WINAPI Direct3DCreate9(UINT a1)
{
	return D3d9ModuleManager::Get().Direct3DCreate9(a1);
}

extern "C" DWORD WINAPI Direct3DCreate9Ex(UINT a1, __int64 a2)
{
	return D3d9ModuleManager::Get().Direct3DCreate9Ex(a1, a2);
}

extern "C" DWORD WINAPI PSGPError()
{
	return D3d9ModuleManager::Get().PSGPError();
}

extern "C" DWORD WINAPI PSGPSampleTexture(int a1, int a2, __int64 a3, unsigned int a4, __int64 a5)
{
	return D3d9ModuleManager::Get().PSGPSampleTexture(a1, a2, a3, a4, a5);
}

