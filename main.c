#include<stdio.h>
#include<stdlib.h>

int mode;
FILE* yaml;
int main() {
	MainMenu:system("cls");
	printf("请选择DNS服务器运行方式：\n\n1.模式1：设置普通级别DNS解析（部分域名会被污染，适合一般海外网站）\n\n2.模式2：运行本地DNS（适合敏感海外网站，不要关闭本窗口与弹出窗口，每次开机需要重新打开）\n\n3.恢复默认DNS（运行模式2时不小心关闭本窗口，可用此选项恢复上网功能）\n\n4.DNS解析结果测试（如需检测模式2的DNS状态，可以新开一个程序窗口来测试）\n\n请输入：");
	scanf("%d", &mode);
	system("cls");
	if (mode == 2) {
		Config_gen();
		printf("正在将DNS解析服务器设置为本地解析（可能会有报错，忽略即可）. . .\n\n");
		system("netsh interface ip set dns \"以太网\" static 127.0.0.1");
		system("netsh interface ip set dns \"WLAN\" static 127.0.0.1");
		system("ipconfig /flushdns");
		printf("\n正在部署DNS解析服务器. . .\n\n");
		printf("注意：如需停止DNS解析请务必先关闭弹出窗口，并在本窗口中按任意键恢复默认DNS设置，否则会导致无法上网！！！\n\n");
		system("start "" /min AdGuardHome.exe");
		printf("如需恢复默认DNS设置，请先关闭弹出窗口，然后");
		system("pause");
		system("netsh interface ip set dns \"以太网\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		system("ipconfig /flushdns");
		printf("\nDNS解析服务器已成功恢复初始设置！\n\n");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 3) {
		system("netsh interface ip set dns \"以太网\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		printf("DNS解析服务器已成功恢复初始设置！\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 1) {
		system("netsh interface ip set dns \"以太网\" static 101.133.211.12");
		system("netsh interface ip set dns \"WLAN\" static 101.133.211.12");
		printf("DNS解析服务器已成功设置为普通级别DNS！\n\n");
		printf("此模式下，谷歌、油管、脸书、推特等敏感域名仍会被污染！\n\n");
		printf("需要完全解析敏感域名请使用模式2！\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 4) {
		system("ipconfig /flushdns");
		printf("\n正在进行DNS解析检测. . .\n\n");
		system("nslookup www.google.com");
		system("nslookup www.youtube.com");
		system("nslookup www.facebook.com");
		system("nslookup twitter.com");
		system("nslookup www.twitch.tv");
		printf("已完成对DNS解析的检测，");
		system("pause");
		goto MainMenu;
	}
	return 0;
}

int Config_gen() {
	if ((yaml = fopen("AdGuardHome.yaml", "r")) == NULL) {
		yaml = fopen("AdGuardHome.yaml", "w");
		fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 114.114.114.114\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 4194304\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n  - tls://dns.sh.zhangmuhan.club\n  filtering_enabled: false\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules: []\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n");
		fclose(yaml);
	}
	else {
		fclose(yaml);
	}
	return 0;
}