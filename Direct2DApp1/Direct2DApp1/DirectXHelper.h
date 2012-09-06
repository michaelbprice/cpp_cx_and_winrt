#pragma once

// Helper utilities to make Win32 APIs work with exceptions.
namespace DX
{
/*
   HDC '12 - Basic - Free-standing functions
   HDC '12 - Intermediate - inlining
*/
	inline void ThrowIfFailed(HRESULT hr)
	{
		if (FAILED(hr))
		{
			// Set a breakpoint on this line to catch Win32 API errors.
			throw Platform::Exception::CreateException(hr);
		}
	}
}
