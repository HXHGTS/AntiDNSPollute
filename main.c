#include<stdio.h>
#include<stdlib.h>

int mode;
FILE* yaml;
int main() {
	MainMenu:system("cls");
	printf("请选择DNS服务器运行方式：\n\n1.模式1：设置普通级别DNS解析（修改完成可以关闭本程序，部分域名会被污染）\n\n2.模式2：运行本地DNS（使用时不要关闭本窗口与弹出窗口，每次使用需要重新打开）\n\n3.恢复默认DNS（运行模式2时未正常退出，可用此选项恢复上网功能）\n\n4.DNS解析结果测试\n\n请输入：");
	scanf("%d", &mode);
	system("cls");
	if (mode == 2) {
		Config_gen();
		printf("正在部署DNS解析服务器. . .\n\n");
		system("start "" /min AdGuardHome.exe");
		printf("正在将DNS解析服务器设置为本地解析（可能会有报错，忽略即可）. . .\n\n");
		system("netsh interface ip set dns \"以太网\" static 127.0.0.1");
		system("netsh interface ipv6 set dns \"以太网\" static ::1");
		system("netsh interface ip set dns \"WLAN\" static 127.0.0.1");
		system("netsh interface ipv6 set dns \"WLAN\" static ::1");
		system("ipconfig /flushdns");
		system("cls");
		printf("正在进行DNS解析检测. . .\n\n");
		printf("正在检测国内网站. . .\n\n");
		printf("正在检测百度解析情况. . .\n\n");
		system("nslookup www.baidu.com ::1");
		printf("正在检测腾讯解析情况. . .\n\n");
		system("nslookup www.qq.com ::1");
		printf("正在检测英雄联盟解析情况. . .\n\n");
		system("nslookup lol.qq.com ::1");
		printf("正在检测王者荣耀解析情况. . .\n\n");
		system("nslookup pvp.qq.com ::1");
		printf("正在检测境外网站. . .\n\n");
		printf("正在检测谷歌解析情况. . .\n\n");
		system("nslookup www.google.com ::1");
		printf("正在检测油管解析情况. . .\n\n");
		system("nslookup www.youtube.com ::1");
		printf("正在检测脸书解析情况. . .\n\n");
		system("nslookup www.facebook.com ::1");
		printf("正在检测推特解析情况. . .\n\n");
		system("nslookup twitter.com ::1");
		printf("正在检测Twitch解析情况. . .\n\n");
		system("nslookup www.twitch.tv ::1");
		printf("已完成对DNS解析的检测！\n\n");
		printf("DNS部署成功！\n\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("使用防污染DNS期间请不要关闭本窗口及其弹出窗口，后台最小化即可. . .\n");
		printf("注意：如需停止DNS解析请务必在本窗口中按任意键恢复默认DNS设置，否则会导致无法上网！！！\n");
		printf("如果不小心关闭本软件，可以重新打开本软件使用模式3恢复默认DNS！！！\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("如需恢复默认DNS设置，");
		system("pause");
		system("taskkill /f /im AdGuardHome.exe");
		system("netsh interface ip set dns \"以太网\" dhcp");
		system("netsh interface ipv6 set dns \"以太网\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		system("netsh interface ipv6 set dns \"WLAN\" dhcp");
		system("ipconfig /flushdns");
		printf("\nDNS解析服务器已成功恢复初始设置！\n\n");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 3) {
		system("taskkill /f /im AdGuardHome.exe");
		system("netsh interface ip set dns \"以太网\" dhcp");
		system("netsh interface ipv6 set dns \"以太网\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		system("netsh interface ipv6 set dns \"WLAN\" dhcp");
		printf("DNS解析服务器已成功恢复初始设置！\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 1) {
		printf("可能会出现较长时间黑屏，请耐心等待. . .\n");
		system("netsh interface ip set dns \"以太网\" static 117.50.10.10");
		system("netsh interface ip add dns \"以太网\" 52.80.52.52 index=2");
		system("netsh interface ip set dns \"WLAN\" static 117.50.10.10");
		system("netsh interface ip add dns \"WLAN\" 52.80.52.52 index=2");
		system("netsh interface ipv6 set dns \"以太网\" static ::1");
		system("netsh interface ipv6 set dns \"WLAN\" static ::1");
		printf("DNS解析服务器已成功设置为ONE DNS！\n\n");
		printf("此模式下，谷歌、油管、脸书、推特、Twitch等敏感域名仍会被污染！\n\n");
		printf("需要完全解析敏感域名请使用模式2！\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 4) {
		system("ipconfig /flushdns");
		printf("\n正在进行DNS解析检测. . .\n\n");
		printf("正在检测国内网站. . .\n\n");
		printf("正在检测百度解析情况. . .\n\n");
		system("nslookup www.baidu.com");
		printf("正在检测腾讯解析情况. . .\n\n");
		system("nslookup www.qq.com");
		printf("正在检测英雄联盟解析情况. . .\n\n");
		system("nslookup lol.qq.com");
		printf("正在检测王者荣耀解析情况. . .\n\n");
		system("nslookup pvp.qq.com");
		printf("正在检测境外网站. . .\n\n");
		printf("正在检测谷歌解析情况. . .\n\n");
		system("nslookup www.google.com");
		printf("正在检测油管解析情况. . .\n\n");
		system("nslookup www.youtube.com");
		printf("正在检测脸书解析情况. . .\n\n");
		system("nslookup www.facebook.com");
		printf("正在检测推特解析情况. . .\n\n");
		system("nslookup twitter.com");
		printf("正在检测Twitch解析情况. . .\n\n");
		system("nslookup www.twitch.tv");
		printf("可将解析出的ip地址放入在线ping工具中检测DNS污染情况！\n\n");
		printf("已完成对DNS解析的检测，");
		system("pause");
		goto MainMenu;
	}
	else {
		goto MainMenu;
	}
	return 0;
}

int Config_gen() {
		yaml = fopen("AdGuardHome.yaml", "w");
		fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 117.50.10.10\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n  - tls://ea-dns.rubyfish.cn\n  - '[/netease.com/]117.50.10.10'\n  - '[/126.net/]117.50.10.10'\n  - '[/icourse163.org/]117.50.10.10'\n  - '[/yeah.net/]117.50.10.10'\n  - '[/126.com/]117.50.10.10'\n  - '[/163.com/]117.50.10.10'\n  - '[/zhangmuhan.club/]117.50.10.10'\n  - '[/google.cn/]117.50.10.10'\n  - '[/baidu.com/]117.50.10.10'\n  - '[/baidupcs.com/]117.50.10.10'\n  - '[/bdstatic.com/]117.50.10.10'\n  - '[/bilibili.com/]117.50.10.10'\n  - '[/bilivideo.com/]117.50.10.10'\n  - '[/hdslb.com/]117.50.10.10'\n  - '[/qq.com/]117.50.10.10'\n  - '[/douyu.com/]117.50.10.10'\n  - '[/huya.com/]117.50.10.10'\n  - '[/aliyun.com/]117.50.10.10'\n  - '[/alicdn.com/]117.50.10.10'\n  - '[/alipay.com/]117.50.10.10'\n  - '[/taobao.com/]117.50.10.10'\n  - '[/tmall.com/]117.50.10.10'\n  - '[/jd.com/]117.50.10.10'\n  - '[/zxxk.com/]117.50.10.10'\n  - '[/cnzz.com/]117.50.10.10'\n  - '[/chaoxing.com/]117.50.10.10'\n  - '[/snnu.edu.cn/]117.50.10.10'\n  - '[/ipip.net/]117.50.10.10'\n  - '[/7moor.com/]117.50.10.10'\n  - '[/t.cn/]117.50.10.10'\n  - '[/chinaz.com/]117.50.10.10'\n  - '[/uzer.me/]117.50.10.10'\n  - '[/lanzou.com/]117.50.10.10'\n  - '[/lanzous.com/]117.50.10.10'\n  - '[/baidupan.com/]117.50.10.10'\n  - '[/zhihu.com/]117.50.10.10'\n  - '[/zhihu.com/]117.50.10.10'\n  - '[/zhimg.com/]117.50.10.10'\n  - '[/cnki.net/]117.50.10.10'\n  - '[/iqiyi.com/]117.50.10.10'\n  - '[/qy.net/]117.50.10.10'\n  - '[/iqiyipic.com/]117.50.10.10'\n  - '[/acfun.cn/]117.50.10.10'\n  - '[/aixifan.com/]117.50.10.10'\n  - '[/yximgs.com/]117.50.10.10'\n  - '[/ksurl.cn/]117.50.10.10'\n  - '[/139.com/]117.50.10.10'\n  - '[/10086.cn/]117.50.10.10'\n  - '[/189.cn/]117.50.10.10'\n  - '[/knet.cn/]117.50.10.10'\n  - '[/10010.cn/]117.50.10.10'\n  - '[/10010.com/]117.50.10.10'\n  - '[/weibo.com/]117.50.10.10'\n  - '[/sina.com.cn/]117.50.10.10'\n  - '[/sohu.com/]117.50.10.10'\n  - '[/cctv.cn/]117.50.10.10'\n  - '[/nn.com/]117.50.10.10'\n  - '[/xunyou.com/]117.50.10.10'\n  - '[/leigod.com/]117.50.10.10'\n  - '[/steampowered.com/]117.50.10.10'\n  - '[/eccdnx.com/]117.50.10.10'\n  - '[/iplaysoft.com/]117.50.10.10'\n  - '[/jianshu.com/]117.50.10.10'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n");
		fclose(yaml);
	return 0;
}