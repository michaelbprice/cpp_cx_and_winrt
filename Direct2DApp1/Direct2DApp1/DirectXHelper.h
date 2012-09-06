#pragma once

// Helper utilities to make Win32 APIs work with exceptions.
namespace DX
{
/*
   STLDODN '12 - Free-standing functions
   STLDODN '12 - inlining
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
