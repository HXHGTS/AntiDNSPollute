#include<stdio.h>
#include<stdlib.h>

int mode;
FILE* yaml;
int main() {
	printf("请选择DNS服务器运行方式：\n1.安装DNS服务器（开机自启）\n2.运行（不要关闭本窗口，每次需要重新打开）\n3.恢复默认DNS\n请输入：");
	scanf("%d", &mode);
	system("cls");
	if (mode == 1) {
		Config_gen();
		printf("正在安装DNS解析服务器. . .\n");
		system("AdGuardHome.exe -s install");
		printf("成功将DNS解析服务器放入System. . .\n");
		printf("正在登录DNS后台. . .\n");
		printf("用户名：root，默认密码：root\n");
		system("explorer http://127.0.0.1");
		system("netsh interface ip set dns \"以太网\" static 127.0.0.1");
		printf("DNS已部署，已将本地DNS服务器自动设置为127.0.0.1！\n");
		system("ipconfig /flushdns");
		printf("正在进行DNS解析检测. . .\n");
		system("nslookup www.google.com");
		system("nslookup www.youtube.com");
		system("nslookup www.facebook.com");
		system("nslookup twitter.com");
		system("nslookup www.twitch.tv");
		system("pause");
	}
	else if (mode == 2) {
		Config_gen();
		printf("正在部署DNS解析服务器. . .\n");
		system("netsh interface ip set dns \"以太网\" static 127.0.0.1");
		system("AdGuardHome.exe");
		system("pause");
	}
	else {
		system("netsh interface ip set dns \"以太网\" dhcp");
		printf("DNS解析服务器已成功恢复初始设置！\n");
		system("ipconfig /flushdns");
		system("pause");
	}
	return 0;
}

int Config_gen() {
	if ((yaml = fopen("AdGuardHome.yaml", "r")) == NULL) {
		yaml = fopen("AdGuardHome.yaml", "w");
		fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: true\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 114.114.114.114\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 4194304\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n  - https://dns.sh.zhangmuhan.club:444/dns-query\n  - tls://dns.sh.zhangmuhan.club\n  filtering_enabled: false\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules: []\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n");
		fclose(yaml);
	}
	else {
		fclose(yaml);
	}
	return 0;
}