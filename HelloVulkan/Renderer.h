#pragma once
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Dependencies\Vulkan v1.1.85\Include\vulkan\vulkan.h"
#include "Dependencies\glfw v3.2.1\include\GLFW\glfw3.h"

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <map>

#include "QueueFamily.h"

const std::vector<const char*> validationLayers =
{
	"VK_LAYER_LUNARG_standard_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class Renderer
{
public:
	Renderer();

	void run()
	{
		InitWindow();
		InitVulkan();
		GameLoop();
		CleanUp();
	}

private:
	GLFWwindow* m_pWindow;

	VkInstance m_vkInstance;
	VkDebugUtilsMessengerEXT callback;
	VkPhysicalDevice m_physicalDevice;

	const int m_WIDTH = 800;
	const int m_HEIGHT = 600;

	void InitWindow();
	void InitVulkan();
	void GameLoop();
	void CleanUp();
	void CreateInstance();
	void InitDebugCallback();
	std::vector<const char*> GetRequiredExtensions();
	bool CheckValidationLayerSupport();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
	void SelectPhysicalDevice();
	//int RateDevice(VkPhysicalDevice device);
	bool CheckDeviceCompatability(VkPhysicalDevice device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
};

#endif // !__RENDERER_H__