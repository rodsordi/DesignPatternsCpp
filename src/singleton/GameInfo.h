#pragma once
#include <string>
#include <memory>

class GameInfo {
private:
	class StudioInfo {
		friend class GameInfo;

	private:
		std::string name;
		std::string site;

	public:
		StudioInfo(
			std::string name,
			std::string site) :
			name(name),
			site(site)
		{
		}

	public:
		std::string toString() {
			return std::format("StudioInfo: [name: {}, site: {}]", name, site);
		}
	};

private:
	std::string name;
	int version;
	std::unique_ptr<StudioInfo> studio;

private:
	GameInfo(
		std::string name,
		int version,
		std::unique_ptr<StudioInfo> studio) :
		name(name),
		version(version),
		studio(std::move(studio))
	{
	}

public:
	GameInfo(GameInfo& other) = delete;
	GameInfo(GameInfo&& other) = delete;
	void operator=(const GameInfo&) = delete;
	void operator=(const GameInfo&&) = delete;

	static GameInfo& getInstance() {
		static GameInfo instance(
			"MyGame",
			1,
			std::make_unique<GameInfo::StudioInfo>(
				"GameStudio",
				"https://gamestudio.example.com"
			)
		);
		return instance;
	}

	StudioInfo& getStudioInfo() {
		return *studio;
	}

	std::string toString() {
		return std::format("GameInfo: [name: {}, version: {}, studio: {}]", name, version, studio->toString());
	}
};