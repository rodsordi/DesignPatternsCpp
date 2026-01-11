#pragma once
#include <string>
#include <vector>
#include <memory>

class GameMatch {

public:
	enum class Type {
		VERSUS,
		COOP,
		CAMPAIGN
	};

public:
	class Builder {

	private:
		Type type;
		int maxPlayers;
		bool ranked;
		std::vector<std::string> enemies;

	public:
		Builder() {}
		Builder(Builder& other) = delete;
		void operator=(const Builder&) = delete;
		Builder(Builder&&) = default;
		Builder& operator=(Builder&&) = default;

	public:
		std::unique_ptr<GameMatch> build() {
			return std::make_unique<GameMatch>(
				type,
				maxPlayers,
				ranked,
				enemies
			);
		}

	public:
		Builder& setType(const Type type) {
			this->type = type;
			return *this;
		}

		Builder& setMaxPlayers(const int maxPlayers) {
			this->maxPlayers = maxPlayers;
			return *this;
		}

		Builder& setRanked(const bool ranked) {
			this->ranked = ranked;
			return *this;
		}

		Builder& addEnemy(const std::string enemy) {
			enemies.push_back(enemy);
			return *this;
		}

		Builder& clearEnemies() {
			enemies.clear();
			return *this;
		}
	};

private:
	const Type type;
	const int maxPlayers;
	const bool ranked;
	const std::vector<std::string> enemies;

public:
	GameMatch(
		Type type,
		int maxPlayers,
		bool ranked,
		std::vector<std::string> enemies) :
		type(type),
		maxPlayers(maxPlayers),
		ranked(ranked),
		enemies(std::move(enemies))
	{
	}
	GameMatch(GameMatch& other) = delete;
	void operator=(const GameMatch&) = delete;
	GameMatch(GameMatch&&) = delete;
	GameMatch& operator=(GameMatch&&) = delete;

public:
	std::string typeToString() const {
		switch (type) {
		case Type::VERSUS:
			return "VERSUS";
		case Type::COOP:
			return "COOP";
		case Type::CAMPAIGN:
			return "CAMPAIGN";
		default:
			return "UNKNOWN";
		}
	}

	std::string toString() const {
		std::string enemiesStr;
		for (const auto& enemy : enemies) {
			enemiesStr += enemy + ", ";
		}
		return std::format("GameMatch: [type: {}, maxPlayers: {}, ranked: {}, enemies: {}]", typeToString(), maxPlayers, ranked, enemiesStr);
	}
};