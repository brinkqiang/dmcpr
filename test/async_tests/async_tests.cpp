#include <cstddef>
#include <gtest.h>

#include <string>

#include <cpr/cpr.h>

#include "cpr/api.h"
#include "cpr/callback.h"
#include "cpr/cprtypes.h"
#include "cpr/session.h"

TEST(AsyncTests, AsyncTests) {
	// �����첽 GET ����
	auto future = cpr::GetAsync(cpr::Url{ "http://openresty.org" });

	// ������Խ�����������
	std::cout << "���ڴ�����������..." << std::endl;

	// ��ȡ������
	cpr::Response r = future.get();

	// ������
	if (r.status_code == 200) {
		std::cout << "Response Body: " << r.text << std::endl;
	}
	else {
		std::cerr << "Error: " << r.status_code << std::endl;
	}
}

TEST(CallbackTests, CallbackTests) {
	// �����첽 GET ����ʹ�� Lambda ���ʽ��Ϊ�ص�����
	cpr::GetCallback([](cpr::Response r) {
		if (r.status_code == 200) {
			std::cout << "Response Body: " << r.text << std::endl;
		}
		else {
			std::cerr << "Error: " << r.status_code << std::endl;
		}
		}, cpr::Url{ "http://openresty.org" });

	// ������Խ�����������
	std::cout << "���ڴ�����������..." << std::endl;


	// Ϊ��ȷ�����̲߳��������˳������ǿ������һ���򵥵���ͣ
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
