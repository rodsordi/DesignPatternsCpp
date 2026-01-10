#pragma once
#include <string>
#include <memory>
#include <vector>

class GameImmutableInfo {
private:
	class StudioInfo {
		friend class GameImmutableInfo;

		class Address {
			friend class GameImmutableInfo;

		private:
			const std::string street;
			const std::string city;

		public:
			Address(
				std::string street,
				std::string city) :
				street(street),
				city(city)
			{
			}
			Address(Address& other) = delete;
			void operator=(const Address&) = delete;
			Address(Address&&) = default;
			Address& operator=(Address&&) = default;

		public:
			std::string toString() const {
				return std::format("Address: [street: {}, city: {}]", street, city);
			}
		};

	private:
		const std::string name;
		const char clazz;
		const std::vector<std::string> phones;
		const std::vector<Address> addresses;

	public:
		StudioInfo(
			std::string name,
			char clazz,
			std::vector<std::string> phones,
			std::vector<Address> addresses) :
			name(name),
			clazz(clazz),
			phones(std::move(phones)),
			addresses(std::move(addresses))
		{
		}
		StudioInfo(StudioInfo& other) = delete;
		void operator=(const StudioInfo&) = delete;
		StudioInfo(StudioInfo&&) = default;
		StudioInfo& operator=(StudioInfo&&) = default;

	public:
		const std::vector<std::string>& getPhones() const {
			return phones;
		}

		const std::vector<Address>& getAddresses() const {
			return addresses;
		}

		std::string toString() const {
			auto addressesStr = std::string();
			for (const auto& address : addresses) {
				addressesStr += address.toString() + " ";
			}
			return std::format("StudioInfo: [name: {}, class: {}, adresses: {}]", name, clazz, addressesStr);
		}
	};

	

private:
	const std::string name;
	const int version;
	const bool launched;
	const std::unique_ptr<StudioInfo> studio;

private:
	GameImmutableInfo(
		std::string name,
		int version,
		bool launched,
		std::unique_ptr<StudioInfo> studio) :
		name(name),
		version(version),
		launched(launched),
		studio(std::move(studio))
	{
	}

public:
	GameImmutableInfo(GameImmutableInfo& other) = delete;
	void operator=(const GameImmutableInfo&) = delete;

public:
	static GameImmutableInfo& getInstance() {
		std::vector<StudioInfo::Address> adresses;
		adresses.reserve(2);
		adresses.emplace_back("Street 123", "São Paulo");
		adresses.emplace_back("Square 2", "Rio de Janeiro");

		static GameImmutableInfo instance(
			"MyGame",
			1,
			true,
			std::make_unique<StudioInfo>(
				"GameStudio",
				'A',
				std::vector<std::string>{ "123-456-7890", "119-8765-4321" },
				std::move(adresses)
			)
		);
		return instance;
	}

public:
	StudioInfo& getStudio() {
		return *studio;
	}

	std::string toString() const {
		return std::format("GameImmutableInfo: [name: {}, version: {}, launched: {}, studio: {}]", name, version, launched, studio->toString());
	}
};