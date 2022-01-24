#pragma once
#include "HttpWindow.h"

class JdicWindow : public HttpWindow
{
	int rotateMirrors;
public:
	JdicWindow();
	~JdicWindow();
	void LoadConfig();
	void AddClassButtons();
	void UpdateURL(const wchar_t *purl);
	void Translate(SharedString *text, int history_id, bool only_use_history) override;

	wchar_t *FindTranslatedText(wchar_t* html);
	virtual void StripResponse(wchar_t* html, std::wstring* text) const override;
	void DisplayResponse(const wchar_t* text) override;
	int WndProc(LRESULT *output, UINT uMsg, WPARAM wParam, LPARAM lParam);

	friend INT_PTR CALLBACK JdicDialogProc(HWND hWndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	wchar_t *GetTranslationPath(Language src, Language dst, const wchar_t *text);

	std::vector<std::wstring> mirrors;
	int currentMirror;
};
