#include <cstdint>
#include <Windows.h>
#include <lazy_importer.h>
#include <filesystem>


/**
 * \brief The entry point of the DLL
 * \param module 
 * \param call_reason 
 * \param reserved 
 * \return DLL loading status
 */
bool __stdcall DllMain(HMODULE module, const uint32_t call_reason, [[maybe_unused]] void* reserved)
{
	// Check if the module is being loaded
	if (call_reason != DLL_PROCESS_ATTACH)
	{
		return true;
	}

	// Disable thread library calls
	LI_FN(DisableThreadLibraryCalls)(module);

	// Get the full path of module .dll file
	wchar_t module_filename[1024]{'\0'};
	GetModuleFileNameW(module, module_filename, sizeof(module_filename) / sizeof(wchar_t));

	// Parent path of the module .dll file
	const auto dll_path = std::filesystem::path(module_filename).parent_path();

	// Load all .dll files in the plugin folder
	for (const auto plugin_folder = dll_path.wstring() + L"\\Plugins";
	     const auto& entry : std::filesystem::directory_iterator(plugin_folder))
	{
		// Get the full path of the .dll file
		std::wstring dll = entry.path().wstring();

		// Load all .dll files in the plugin folder
		if(dll.ends_with(L".dll"))
			LI_FN(LoadLibraryW)(dll.c_str());
	}
}
