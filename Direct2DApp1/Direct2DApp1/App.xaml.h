﻿//
// App.xaml.h
// Declaration of the App class.
//

#pragma once

/*
   HDC '12 - WinRT XAML Generated header files (partial classes)
*/
#include "App.g.h"
#include "DirectXPage.xaml.h"

namespace Direct2DApp1
{
	/// <summary>
	/// Provides application-specific behavior to supplement the default Application class.
	/// </summary>
	ref class App sealed
	{
	public:
		App();
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ args) override;

	private:
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ args);
		DirectXPage^ m_directXPage;
	};
}
