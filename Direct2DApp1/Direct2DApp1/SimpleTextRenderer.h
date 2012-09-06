#pragma once

/*
   STLDODN '12 - Preprocessor
*/
#include "DirectXBase.h"

/*
   STLDODN '12 - Class Declaration
   STLDODN '12 - Inheritance (single)
*/
// This class renders simple text with a colored background.
ref class SimpleTextRenderer sealed : public DirectXBase
{
/*
   STLDODN '12 - Class Member Accessibility
   STLDODN '12 - internal Accessibility for WinRT classes
*/
public:
/*
   STLDODN '12 - Declaration vs. Implementation (decl)
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
   STLDODN '12 - Namespaces
   STLDODN '12 - Scope Resolution Operator '::'
   STLDODN '12 - Windows Runtime Library
*/
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> m_blackBrush;
	Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat;
	Microsoft::WRL::ComPtr<IDWriteTextLayout> m_textLayout;
	DWRITE_TEXT_METRICS m_textMetrics;
	Windows::Foundation::Point m_textPosition;
	bool m_renderNeeded;
	int m_backgroundColorIndex;
/*
   STLDODN '12 - Semicolons
*/
};
