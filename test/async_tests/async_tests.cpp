#include <cstddef>
#include <gtest.h>

#include <string>

#include <cpr/cpr.h>

#include "cpr/api.h"
#include "cpr/callback.h"
#include "cpr/cprtypes.h"
#include "cpr/session.h"

TEST(AsyncTests, AsyncTests) {
	// 发起异步 GET 请求
	auto future = cpr::GetAsync(cpr::Url{ "http://openresty.org" });

	// 这里可以进行其他操作
	std::cout << "正在处理其他任务..." << std::endl;

	// 获取请求结果
	cpr::Response r = future.get();

	// 输出结果
	if (r.status_code == 200) {
		std::cout << "Response Body: " << r.text << std::endl;
	}
	else {
		std::cerr << "Error: " << r.status_code << std::endl;
	}
}

TEST(CallbackTests, CallbackTests) {
	// 发起异步 GET 请求并使用 Lambda 表达式作为回调函数
	cpr::GetCallback([](cpr::Response r) {
		if (r.status_code == 200) {
			std::cout << "Response Body: " << r.text << std::endl;
		}
		else {
			std::cerr << "Error: " << r.status_code << std::endl;
		}
		}, cpr::Url{ "http://openresty.org" });

	// 这里可以进行其他操作
	std::cout << "正在处理其他任务..." << std::endl;


	// 为了确保主线程不会立即退出，我们可以添加一个简单的暂停
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
