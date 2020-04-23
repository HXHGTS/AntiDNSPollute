#include<stdio.h>
#include<stdlib.h>

int mode,DNSSet;
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
		printf("正在进行本地ipv4 DNS解析检测. . .\n\n");
		printf("正在检测国内网站. . .\n\n");
		printf("正在检测百度解析情况. . .\n\n");
		system("nslookup www.baidu.com 127.0.0.1");
		printf("正在检测腾讯解析情况. . .\n\n");
		system("nslookup www.qq.com 127.0.0.1");
		printf("正在检测英雄联盟解析情况. . .\n\n");
		system("nslookup lol.qq.com 127.0.0.1");
		printf("正在检测王者荣耀解析情况. . .\n\n");
		system("nslookup pvp.qq.com 127.0.0.1");
		printf("正在检测境外网站. . .\n\n");
		printf("正在检测谷歌解析情况. . .\n\n");
		system("nslookup www.google.com 127.0.0.1");
		printf("正在检测油管解析情况. . .\n\n");
		system("nslookup www.youtube.com 127.0.0.1");
		printf("正在检测脸书解析情况. . .\n\n");
		system("nslookup www.facebook.com 127.0.0.1");
		printf("正在检测推特解析情况. . .\n\n");
		system("nslookup twitter.com 127.0.0.1");
		printf("正在检测Twitch解析情况. . .\n\n");
		system("nslookup www.twitch.tv 127.0.0.1");
		printf("已完成对本地ipv4 DNS解析的检测！\n\n");
		printf("正在进行本地ipv6 DNS解析检测. . .\n\n");
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
		printf("已完成对本地ipv6 DNS解析的检测！\n\n");
		printf("已完成所有DNS解析的检测！\n\n");
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
		printf("使用仅支持ipv4的DNS时请关闭计算机的ipv6功能，避免优先使用ipv6 DNS解析！\n\n");
		printf("请选择你想用的DNS：\n\n1.韩国KT DNS（仅ipv4）\n\n2.韩国SK DNS（仅ipv4）\n\n3.韩国LG U+ DNS（仅ipv4）\n\n4.台湾中华电信HiNet DNS（仅ipv4）\n\n5.台湾TWNIC DNS（ipv4+ipv6）\n\n6.中国大陆CNNIC DNS（ipv4+ipv6）\n\n请输入：");
		scanf("%d", &DNSSet);
		system("cls");
		printf("可能会出现较长时间黑屏，请耐心等待. . .\n");
		if (DNSSet == 1) {
			system("netsh interface ip set dns \"以太网\" static 168.126.63.1");
			system("netsh interface ip add dns \"以太网\" 168.126.63.2 index=2");
			system("netsh interface ip set dns \"WLAN\" static 168.126.63.1");
			system("netsh interface ip add dns \"WLAN\" 168.126.63.2 index=2");
		}
		else if (DNSSet == 2) {
			system("netsh interface ip set dns \"以太网\" static 210.220.163.82");
			system("netsh interface ip set dns \"WLAN\" static 210.220.163.82");
		}
		else if (DNSSet == 3) {
			system("netsh interface ip set dns \"以太网\" static 164.124.101.2");
			system("netsh interface ip add dns \"以太网\" 203.248.252.2 index=2");
			system("netsh interface ip set dns \"WLAN\" static 164.124.101.2");
			system("netsh interface ip add dns \"WLAN\" 203.248.252.2 index=2");
		}
		else if (DNSSet == 4) {
			system("netsh interface ip set dns \"以太网\" static 168.95.1.1");
			system("netsh interface ip add dns \"以太网\" 168.95.192.1 index=2");
			system("netsh interface ip set dns \"WLAN\" static 168.95.1.1");
			system("netsh interface ip add dns \"WLAN\" 168.95.192.1 index=2");
		}
		else if (DNSSet == 5) {
			system("netsh interface ip set dns \"以太网\" static 101.101.101.101");
			system("netsh interface ip add dns \"以太网\" 101.102.103.104 index=2");
			system("netsh interface ip set dns \"WLAN\" static 101.101.101.101");
			system("netsh interface ip add dns \"WLAN\" 101.102.103.104 index=2");
			system("netsh interface ipv6 set dns \"以太网\" static 2001:de4::101");
			system("netsh interface ipv6 add dns \"以太网\" 2001:de4::102 index=2");
			system("netsh interface ipv6 set dns \"WLAN\" static 2001:de4::101");
			system("netsh interface ipv6 add dns \"WLAN\" 2001:de4::102 index=2");
		}
		else {
			system("netsh interface ip set dns \"以太网\" static 1.2.4.8");
			system("netsh interface ip add dns \"以太网\" 210.2.4.8 index=2");
			system("netsh interface ip set dns \"WLAN\" static 1.2.4.8");
			system("netsh interface ip add dns \"WLAN\" 210.2.4.8 index=2");
			system("netsh interface ipv6 set dns \"以太网\" static 240c::6666");
			system("netsh interface ipv6 add dns \"以太网\" 240c::6644 index=2");
			system("netsh interface ipv6 set dns \"WLAN\" static 240c::6666");
			system("netsh interface ipv6 add dns \"WLAN\" 240c::6644 index=2");
		}
		if(DNSSet==1)printf("DNS解析服务器已成功设置为%s！\n\n","韩国KT DNS");
		else if (DNSSet == 2)printf("DNS解析服务器已成功设置为%s！\n\n", "韩国SK DNS");
		else if (DNSSet == 3)printf("DNS解析服务器已成功设置为%s！\n\n", "韩国LG U+ DNS");
		else if (DNSSet == 4)printf("DNS解析服务器已成功设置为%s！\n\n", "台湾中华电信HiNet DNS");
		else if (DNSSet == 5)printf("DNS解析服务器已成功设置为%s！\n\n", "台湾TWNIC DNS");
		else printf("DNS解析服务器已成功设置为%s！\n\n", "中国大陆CNNIC DNS");
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
	int area;
	printf("指定上游DNS服务器区域：\n\n1.红鱼DNS（主干网节点）\n\n2.红鱼DNS（亚洲东部）\n\n3.红鱼DNS（美国西部）\n\n4.GoogleDNS（中国香港）\n\n5.OpenDNS（中国香港）\n\n6.AdGuardDNS（日本东京）\n\n7.CloudflareDNS（日本大阪）\n\n请输入：");
	scanf("%d", &area);
		yaml = fopen("AdGuardHome.yaml", "w");
		if(area==1)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 119.29.29.29\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n","  - tls://dns.rubyfish.cn\n");
		else if (area == 2)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 119.29.29.29\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", "  - tls://ea-dns.rubyfish.cn\n");
		else if (area == 3)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 119.29.29.29\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n","  - tls://uw-dns.rubyfish.cn\n");
		else if (area == 4)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 119.29.29.29\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", "  - tls://dns.google\n");
		else if (area == 5)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 119.29.29.29\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", "  - 208.67.222.222:5353\n  - 208.67.222.220:5353\n");
		else if (area == 6)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 119.29.29.29\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", "  - tls://dns.adguard.com\n  - https://dns.adguard.com/dns-query\n");
		else fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 119.29.29.29\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", "  - tls://1dot1dot1dot1.cloudflare-dns.com\n  - https://dns.cloudflare.com/dns-query\n");
		fclose(yaml);
		system("cls");
		if(area==1)printf("已选定：%s\n\n","红鱼DNS（主干网节点）");
		else if (area == 2)printf("已选定：%s\n\n", "红鱼DNS（亚洲东部）");
		else if (area == 3)printf("已选定：%s\n\n", "红鱼DNS（美国西部）");
		else if (area == 4)printf("已选定：%s\n\n", "GoogleDNS（中国香港）");
		else if (area == 5)printf("已选定：%s\n\n", "OpenDNS（中国香港）");
		else if (area == 6)printf("已选定：%s\n\n", "AdGuardDNS（日本东京）");
		else printf("已选定：%s\n\n", "CloudflareDNS（日本大阪）");
	return 0;
}
