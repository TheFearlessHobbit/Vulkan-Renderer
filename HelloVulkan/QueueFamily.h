#pragma once
#ifndef __QUEUEFAMILY_H__
#define __QUEUEFAMILY_H__

#include <optional>

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;

	bool IsComplete()
	{
		return graphicsFamily.has_value();
	}
};

#endif // !__QUEUEFAMILY_H__