#pragma once
#include "Math/Math.h"
#include "Renderer/RendererEnums.h"

using namespace TEN::Math;

namespace TEN::Config
{
	// Directories

	constexpr auto REGKEY_ROOT		   = "Software\\TombEngine\\1.4.0";
	constexpr auto REGKEY_CONTROLS	   = "Controls";
	constexpr auto REGKEY_KEY_BINDINGS = "KeyBindings";
	constexpr auto REGKEY_GAMEPLAY	   = "Gameplay";
	constexpr auto REGKEY_GRAPHICS	   = "Graphics";
	constexpr auto REGKEY_SOUND		   = "Sound";

	// Controls keys

	constexpr auto REGKEY_ENABLE_TANK_CAMERA_CONTROL = "EnableTankCameraControl";
	constexpr auto REGKEY_INVERT_CAMERA_X_AXIS		 = "InvertCameraXAxis";
	constexpr auto REGKEY_INVERT_CAMERA_Y_AXIS		 = "InvertCameraYAxis";
	constexpr auto REGKEY_ENABLE_RUMBLE				 = "EnableRumble";
	constexpr auto REGKEY_MOUSE_SENSITIVITY			 = "MouseSensitivity";
	constexpr auto REGKEY_MENU_OPTION_LOOPING_MODE	 = "MenuOptionLoopingMode";

	// Gameplay keys

	constexpr auto REGKEY_CONTROL_MODE					= "ControlMode";
	constexpr auto REGKEY_SWIM_CONTROL_MODE				= "SwimControlMode";
	constexpr auto REGKEY_ENABLE_WALK_TOGGLE			= "EnableWalkToggle";
	constexpr auto REGKEY_ENABLE_CROUCH_TOGGLE			= "EnableCrouchToggle";
	constexpr auto REGKEY_ENABLE_CLIMB_TOGGLE			= "EnableClimbToggle";
	constexpr auto REGKEY_ENABLE_AUTO_MONKEY_SWING_JUMP = "EnableAutoMonkeySwingJump";
	constexpr auto REGKEY_ENABLE_AUTO_TARGETING			= "EnableAutoTargeting";
	constexpr auto REGKEY_ENABLE_OPPOSITE_ACTION_ROLL	= "EnableOppositeActionRoll";
	constexpr auto REGKEY_ENABLE_TARGET_HIGHLIGHTER		= "EnableTargetHighlighter";
	constexpr auto REGKEY_ENABLE_SUBTITLES				= "EnableSubtitles";

	// Graphics keys
	constexpr auto REGKEY_SCREEN_WIDTH				= "ScreenWidth";
	constexpr auto REGKEY_SCREEN_HEIGHT				= "ScreenHeight";
	constexpr auto REGKEY_WINDOW_MODE				= "WindowMode";
	constexpr auto REGKEY_FRAME_RATE_MODE			= "FrameRateMode";
	constexpr auto REGKEY_SHADOWS					= "ShadowsMode";
	constexpr auto REGKEY_SHADOW_MAP_SIZE			= "ShadowMapSize";
	constexpr auto REGKEY_SHADOW_BLOB_COUNT_MAX		= "ShadowBlobCountMax";
	constexpr auto REGKEY_ENABLE_CAUSTICS			= "EnableCaustics";
	constexpr auto REGKEY_ANTIALIASING_MODE			= "AntialiasingMode";
	constexpr auto REGKEY_AMBIENT_OCCLUSION			= "AmbientOcclusion";

	// Sound keys

	constexpr auto REGKEY_SOUND_DEVICE	= "SoundDevice";
	constexpr auto REGKEY_ENABLE_SOUND	= "EnableSound";
	constexpr auto REGKEY_ENABLE_REVERB = "EnableReverb";
	constexpr auto REGKEY_MUSIC_VOLUME	= "MusicVolume";
	constexpr auto REGKEY_SFX_VOLUME	= "SfxVolume";

	enum class MenuOptionLoopingMode
	{
		AllMenus,
		SaveLoadOnly,
		Off,

		Count
	};

	enum class ControlMode
	{
		Classic,
		Enhanced,
		Modern,

		Count
	};

	enum class SwimControlMode
	{
		Omnidirectional,
		Planar,

		Count
	};

	enum class WindowMode
	{
		Windowed,
		Fullscreen,

		Count
	};

	enum class FrameRateMode
	{
		Thirty,
		Sixty,
		//Unlimited,

		Count
	};

	struct GameConfiguration
	{
		static constexpr auto DEFAULT_MOUSE_SENSITIVITY		= 6;
		static constexpr auto DEFAULT_SHADOW_MAP_SIZE		= 1024;
		static constexpr auto DEFAULT_SHADOW_BLOB_COUNT_MAX	= 16;
		static constexpr auto MOUSE_SENSITIVITY_MAX			= 35;
		static constexpr auto MOUSE_SENSITIVITY_MIN			= 1;
		static constexpr auto SOUND_VOLUME_MAX				= 100;

		// Controls

		std::vector<int>	  KeyBindings			  = {};
		bool				  EnableTankCameraControl = false;
		bool				  InvertCameraXAxis		  = false;
		bool				  InvertCameraYAxis		  = false;
		bool				  EnableRumble			  = false;
		int					  MouseSensitivity		  = DEFAULT_MOUSE_SENSITIVITY;
		MenuOptionLoopingMode MenuOptionLoopingMode	  = MenuOptionLoopingMode::SaveLoadOnly;

		// Gameplay

		ControlMode		ControlMode				  = ControlMode::Classic;
		SwimControlMode SwimControlMode			  = SwimControlMode::Omnidirectional;
		bool			EnableWalkToggle		  = false;
		bool			EnableCrouchToggle		  = false;
		bool			EnableClimbToggle		  = false;
		bool			EnableAutoMonkeySwingJump = false;
		bool			EnableAutoTargeting		  = false;
		bool			EnableOppositeActionRoll  = false;
		bool			EnableTargetHighlighter	  = false;
		bool			EnableSubtitles			  = false;
		
		// Graphics

		int				 ScreenWidth			= 0;
		int				 ScreenHeight			= 0;
		WindowMode		 WindowMode				= WindowMode::Windowed;
		FrameRateMode	 FrameRateMode			= FrameRateMode::Thirty;
		ShadowMode		 ShadowType				= ShadowMode::None;
		int				 ShadowMapSize			= DEFAULT_SHADOW_MAP_SIZE;
		int				 ShadowBlobCountMax		= DEFAULT_SHADOW_BLOB_COUNT_MAX;
		bool			 EnableCaustics			= false;
		bool			 EnableAmbientOcclusion = false;
		AntialiasingMode AntialiasingMode		= AntialiasingMode::None;

		// Sound

		int	 SoundDevice  = 0;
		bool EnableSound  = false;
		bool EnableReverb = false;
		int	 MusicVolume  = 0;
		int	 SfxVolume	  = 0;

		std::vector<Vector2i> SupportedScreenResolutions = {};
		std::string			  AdapterName				 = {};

		// Inquirers

		bool IsUsingClassicControls() const;
		bool IsUsingEnhancedControls() const;
		bool IsUsingModernControls() const;
		bool IsUsingOmnidirectionalSwimControls() const;
		bool IsUsingPlanarSwimControls() const;
	};

	extern GameConfiguration g_Config;

	int	 SetupDialog();
	void InitDefaultConfiguration();
	bool LoadConfiguration();
	bool SaveConfiguration();
}
