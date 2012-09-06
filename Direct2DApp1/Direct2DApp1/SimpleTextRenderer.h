#pragma once

/*
   HDC '12 - Basic - Preprocessor
*/
#include "DirectXBase.h"

/*
   HDC '12 - Basic - Class Declaration
   HDC '12 - Basic - Inheritance (single)
*/
// This class renders simple text with a colored background.
ref class SimpleTextRenderer sealed : public DirectXBase
{
/*
   HDC '12 - Basic - Class Member Accessibility
   HDC '12 - WinRT internal Accessibility for classes
*/
public:
/*
   HDC '12 - Basic - Declaration vs. Implementation (decl)
*/
	SimpleTextRenderer();

	// DirectXBase methods.
	virtual void CreateDeviceIndependentResources() override;
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;
	virtual void Render() override;

	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);

	// Method to change the text position based on input events.
	void UpdateTextPosition(Windows::Foundation::Point deltaTextPosition);

	// Methods to adjust the window background color.
	void BackgroundColorNext();
	void BackgroundColorPrevious();

	// Methods to save and load state in response to suspend.
	void SaveInternalState(Windows::Foundation::Collections::IPropertySet^ state);
	void LoadInternalState(Windows::Foundation::Collections::IPropertySet^ state);

private:
/*
   HDC '12 - Intermediate - Namespaces
   HDC '12 - Intermediate - Scope Resolution Operator '::'
   HDC '12 - WinRT Windows Runtime Library
*/
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> m_blackBrush;
	Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat;
	Microsoft::WRL::ComPtr<IDWriteTextLayout> m_textLayout;
	DWRITE_TEXT_METRICS m_textMetrics;
	Windows::Foundation::Point m_textPosition;
	bool m_renderNeeded;
	int m_backgroundColorIndex;
/*
   HDC '12 - Basic - Semicolons
*/
};
