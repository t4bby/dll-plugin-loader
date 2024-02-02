#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include <Shlwapi.h>
#include <Shlobj.h>
#pragma comment(lib, "shlwapi.lib")

// An inheritable class to disallow the copy constructor and operator= functions
class NonCopyable
{
protected:
	NonCopyable()
	{
	}

	NonCopyable(const NonCopyable&&)
	{
	}

	void operator=(const NonCopyable&&)
	{
	}

private:
	NonCopyable(NonCopyable&);
	NonCopyable& operator=(NonCopyable& other);
};


class D3d9ModuleManager : NonCopyable
{
public:
	DWORD Direct3DCreate9On12Ex(__int64 a1, __int64 a2, int a3, __int64 a4)
	{
		if (!m_Direct3DCreate9On12Ex)
		{
			return ERROR_SUCCESS;
		}
		return m_Direct3DCreate9On12Ex(a1, a2, a3, a4);
	}

	DWORD Direct3DShaderValidatorCreate9()
	{
		if (!m_Direct3DShaderValidatorCreate9)
		{
			return ERROR_SUCCESS;
		}
		return m_Direct3DShaderValidatorCreate9();
	}

	DWORD D3DPERF_BeginEvent(unsigned int a1, __int64 a2)
	{
		if (!m_D3DPERF_BeginEvent)
		{
			return ERROR_SUCCESS;
		}
		return m_D3DPERF_BeginEvent(a1, a2);
	}

	DWORD D3DPERF_EndEvent()
	{
		if (!m_D3DPERF_EndEvent)
		{
			return ERROR_SUCCESS;
		}
		return m_D3DPERF_EndEvent();
	}

	DWORD D3DPERF_GetStatus()
	{
		if (!m_D3DPERF_GetStatus)
		{
			return ERROR_SUCCESS;
		}
		return m_D3DPERF_GetStatus();
	}

	DWORD D3DPERF_QueryRepeatFrame()
	{
		if (!m_D3DPERF_QueryRepeatFrame)
		{
			return ERROR_SUCCESS;
		}
		return m_D3DPERF_QueryRepeatFrame();
	}

	DWORD D3DPERF_SetMarker(unsigned int a1, __int64 a2)
	{
		if (!m_D3DPERF_SetMarker)
		{
			return ERROR_SUCCESS;
		}
		return m_D3DPERF_SetMarker(a1, a2);
	}

	DWORD D3DPERF_SetOptions(unsigned int a1, __int64 a2)
	{
		if (!m_D3DPERF_SetOptions)
		{
			return ERROR_SUCCESS;
		}
		return m_D3DPERF_SetOptions(a1, a2);
	}

	DWORD D3DPERF_SetRegion(unsigned int a1, __int64 a2)
	{
		if (!m_D3DPERF_SetRegion)
		{
			return ERROR_SUCCESS;
		}
		return m_D3DPERF_SetRegion(a1, a2);
	}

	DWORD DebugSetLevel()
	{
		if (!m_DebugSetLevel)
		{
			return ERROR_SUCCESS;
		}
		return m_DebugSetLevel();
	}

	DWORD DebugSetMute()
	{
		if (!m_DebugSetMute)
		{
			return ERROR_SUCCESS;
		}
		return m_DebugSetMute();
	}

	DWORD Direct3DCreate9(UINT SDKVersion)
	{
		if (!m_Direct3DCreate9)
		{
			return ERROR_SUCCESS;
		}

		return m_Direct3DCreate9(SDKVersion);
	}

	DWORD PSGPError()
	{
		if (!m_PSGPError)
		{
			return ERROR_SUCCESS;
		}
		return m_PSGPError();
	}

	DWORD PSGPSampleTexture(int a1, int a2, __int64 a3, unsigned int a4, __int64 a5)
	{
		if (!m_PSGPSampleTexture)
		{
			return ERROR_SUCCESS;
		}
		return m_PSGPSampleTexture(a1, a2, a3, a4, a5);
	}

	DWORD Direct3DCreate9Ex(__int64 a1, __int64 a2)
	{
		if (!m_Direct3DCreate9Ex)
		{
			return ERROR_SUCCESS;
		}
		return m_Direct3DCreate9Ex(a1, a2);
	}

	D3d9ModuleManager():
		m_Direct3DCreate9On12Ex(nullptr),
		m_Direct3DShaderValidatorCreate9(nullptr),
		m_PSGPError(nullptr),
		m_PSGPSampleTexture(nullptr),
		m_D3DPERF_BeginEvent(nullptr),
		m_D3DPERF_EndEvent(nullptr),
		m_D3DPERF_GetStatus(nullptr),
		m_D3DPERF_QueryRepeatFrame(nullptr),
		m_D3DPERF_SetMarker(nullptr),
		m_D3DPERF_SetOptions(nullptr),
		m_D3DPERF_SetRegion(nullptr),
		m_DebugSetLevel(nullptr),
		m_DebugSetMute(nullptr),
		m_Direct3DCreate9(nullptr),
		m_Direct3DCreate9Ex(nullptr)
	{
		std::unique_ptr<char[]> system_directory(new char[MAX_PATH]);
		GetSystemDirectoryA(system_directory.get(), MAX_PATH);

		const std::string lib_path(system_directory.get());
		std::unique_ptr<char[]> buffer(new char[MAX_PATH]);
		const std::string path = PathCombineA(buffer.get(), lib_path.c_str(), "d3d9.dll");

		m_module = LoadLibraryA(path.c_str());
		if (!m_module)
		{
			HRESULT hr = GetLastError();
			std::unique_ptr<char[]> error_msg(new char[MAX_PATH]);
			MessageBoxA(NULL, error_msg.get(), "Error", MB_ICONERROR);
			exit(hr);
		}

		GetProcAddress("Direct3DCreate9On12Ex", &m_Direct3DCreate9On12Ex);
		GetProcAddress("Direct3DShaderValidatorCreate9", &m_Direct3DShaderValidatorCreate9);
		GetProcAddress("PSGPError", &m_PSGPError);
		GetProcAddress("PSGPSampleTexture", &m_PSGPSampleTexture);
		GetProcAddress("D3DPERF_BeginEvent", &m_D3DPERF_BeginEvent);
		GetProcAddress("D3DPERF_EndEvent", &m_D3DPERF_EndEvent);
		GetProcAddress("D3DPERF_GetStatus", &m_D3DPERF_GetStatus);
		GetProcAddress("D3DPERF_QueryRepeatFrame", &m_D3DPERF_QueryRepeatFrame);
		GetProcAddress("D3DPERF_SetMarker", &m_D3DPERF_SetMarker);
		GetProcAddress("D3DPERF_SetOptions", &m_D3DPERF_SetOptions);
		GetProcAddress("D3DPERF_SetRegion", &m_D3DPERF_SetRegion);
		GetProcAddress("DebugSetLevel", &m_DebugSetLevel);
		GetProcAddress("DebugSetMute", &m_DebugSetMute);
		GetProcAddress("Direct3DCreate9", &m_Direct3DCreate9);
		GetProcAddress("Direct3DCreate9Ex", &m_Direct3DCreate9Ex);
	}

	~D3d9ModuleManager()
	{
		if (m_module)
		{
			std::string d3d9_path;
			FreeLibrary(m_module);
		}
	}

	static D3d9ModuleManager& Get()
	{
		static D3d9ModuleManager instance;
		return instance;
	}

private:
	DWORD (WINAPI*m_Direct3DCreate9On12Ex)(__int64 a1, __int64 a2, int a3, __int64 a4);
	DWORD (WINAPI*m_Direct3DShaderValidatorCreate9)();
	DWORD (WINAPI*m_PSGPError)();
	DWORD (WINAPI*m_PSGPSampleTexture)(int a1, int a2, __int64 a3, unsigned int a4, __int64 a5);
	DWORD (WINAPI*m_D3DPERF_BeginEvent)(unsigned int a1, __int64 a2);
	DWORD (WINAPI*m_D3DPERF_EndEvent)();
	DWORD (WINAPI*m_D3DPERF_GetStatus)();
	DWORD (WINAPI*m_D3DPERF_QueryRepeatFrame)();
	DWORD (WINAPI*m_D3DPERF_SetMarker)(unsigned int a1, __int64 a2);
	DWORD (WINAPI*m_D3DPERF_SetOptions)(unsigned int a1, __int64 a2);
	DWORD (WINAPI*m_D3DPERF_SetRegion)(unsigned int a1, __int64 a2);
	DWORD (WINAPI*m_DebugSetLevel)();
	DWORD (WINAPI*m_DebugSetMute)();
	DWORD (WINAPI*m_Direct3DCreate9)(UINT SDKVersion);
	DWORD (WINAPI*m_Direct3DCreate9Ex)(__int64 a1, __int64 a2);

	template <typename T>
	inline void GetProcAddress(const char* funcname, T* ppfunc)
	{
		*ppfunc = reinterpret_cast<T>(::GetProcAddress(m_module, funcname));
	}

	HMODULE m_module;
};
