#pragma once
#include <string>
#include <memory>

class GameInfo {
public:
	class StudioInfo {
		friend class GameInfo;

	private:
		std::string name;
		std::string site;

	private:
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
	inline static GameInfo* instance = nullptr;
	std::string name;
	int version;
	GameInfo::StudioInfo* studio;

private:
	GameInfo(
		std::string name,
		int version,
		GameInfo::StudioInfo* studio) :
		name(name),
		version(version),
		studio(studio)
	{
	}

public:
	GameInfo(GameInfo& other) = delete;

	void operator=(const GameInfo&) = delete;

	static GameInfo* getInstance() {
		if (instance == nullptr) {
			instance = new GameInfo(
				"MyGame",
				1,
				new GameInfo::StudioInfo(
					"GameStudio",
					"https://gamestudio.example.com"
				)
			);
		}
		return instance;
	}

	std::string toString() {
		return std::format("GameInfo: [name: {}, version: {}, studio: {}]", name, version, studio->toString());
	}
};