#include<stdio.h>
#include<stdlib.h>

int mode;
FILE* yaml;
int main() {
	MainMenu:system("cls");
	printf("��ѡ��DNS���������з�ʽ��\n\n1.ģʽ1��������ͨ����DNS�������޸���ɿ��Թرձ����򣬲��������ᱻ��Ⱦ��\n\n2.ģʽ2�����б���DNS��ʹ��ʱ��Ҫ�رձ������뵯�����ڣ�ÿ��ʹ����Ҫ���´򿪣�\n\n3.�ָ�Ĭ��DNS������ģʽ2ʱδ�����˳������ô�ѡ��ָ��������ܣ�\n\n4.DNS�����������\n\n�����룺");
	scanf("%d", &mode);
	system("cls");
	if (mode == 2) {
		Config_gen();
		printf("���ڲ���DNS����������. . .\n\n");
		system("start "" /min AdGuardHome.exe");
		printf("���ڽ�DNS��������������Ϊ���ؽ��������ܻ��б������Լ��ɣ�. . .\n\n");
		system("netsh interface ip set dns \"��̫��\" static 127.0.0.1");
		system("netsh interface ip set dns \"WLAN\" static 127.0.0.1");
		system("ipconfig /flushdns");
		system("cls");
		printf("���ڽ���DNS�������. . .\n\n");
		system("nslookup www.google.com");
		system("nslookup www.youtube.com");
		system("nslookup www.facebook.com");
		system("nslookup twitter.com");
		system("nslookup www.twitch.tv");
		printf("����ɶ�DNS�����ļ�⣡\n\n");
		printf("DNS����ɹ���\n\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("ע�⣺����ֹͣDNS����������ڱ������а�������ָ�Ĭ��DNS���ã�����ᵼ���޷�����������\n");
		printf("�����С�Ĺرձ�������������´򿪱����ʹ��ģʽ3�ָ�Ĭ��DNS������\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("����ָ�Ĭ��DNS���ã���");
		system("pause");
		system("taskkill /f /im AdGuardHome.exe");
		system("netsh interface ip set dns \"��̫��\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		system("ipconfig /flushdns");
		printf("\nDNS�����������ѳɹ��ָ���ʼ���ã�\n\n");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 3) {
		system("taskkill /f /im AdGuardHome.exe");
		system("netsh interface ip set dns \"��̫��\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		printf("DNS�����������ѳɹ��ָ���ʼ���ã�\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 1) {
		printf("���ܻ���ֽϳ�ʱ������������ĵȴ�. . .\n");
		system("netsh interface ip set dns \"��̫��\" static 168.126.63.1");
		system("netsh interface ip add dns \"��̫��\" 168.126.63.2 index=2");
		system("netsh interface ip set dns \"WLAN\" static 168.126.63.1");
		system("netsh interface ip add dns \"WLAN\" 168.126.63.2 index=2");
		printf("DNS�����������ѳɹ�����Ϊ��ͨ����DNS��\n\n");
		printf("��ģʽ�£��ȸ衢�͹ܡ����顢���ء�Twitch�����������Իᱻ��Ⱦ��\n\n");
		printf("��Ҫ��ȫ��������������ʹ��ģʽ2��\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 4) {
		system("ipconfig /flushdns");
		printf("\n���ڽ���DNS�������. . .\n\n");
		system("nslookup www.google.com");
		system("nslookup www.youtube.com");
		system("nslookup www.facebook.com");
		system("nslookup twitter.com");
		system("nslookup www.twitch.tv");
		printf("����ɶ�DNS�����ļ�⣬");
		system("pause");
		goto MainMenu;
	}
	return 0;
}

int Config_gen() {
		yaml = fopen("AdGuardHome.yaml", "w");
		fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 223.5.5.5\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: true\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 4194304\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n  - 101.133.211.12:55\n  - [/netease.com/]114.114.114.114\n  - [/126.net/]114.114.114.114\n  - [/icourse163.org/]114.114.114.114\n  - [/yeah.net/]114.114.114.114\n  - [/126.com/]114.114.114.114\n  - [/163.com/]114.114.114.114\n  - [/zhangmuhan.club/]114.114.114.114\n  - [/google.cn/]114.114.114.114\n  - [/baidu.com/]114.114.114.114\n  - [/baidupcs.com/]114.114.114.114\n  - [/bdstatic.com/]114.114.114.114\n  - [/bilibili.com/]114.114.114.114\n  - [/bilivideo.com/]114.114.114.114\n  - [/hdslb.com/]114.114.114.114\n  - [/qq.com/]114.114.114.114\n  - [/douyu.com/]114.114.114.114\n  - [/huya.com/]114.114.114.114\n  - [/aliyun.com/]114.114.114.114\n  - [/alicdn.com/]114.114.114.114\n  - [/alipay.com/]114.114.114.114\n  - [/taobao.com/]114.114.114.114\n  - [/tmall.com/]114.114.114.114\n  - [/jd.com/]114.114.114.114\n  - [/zxxk.com/]114.114.114.114\n  - [/cnzz.com/]114.114.114.114\n  - [/chaoxing.com/]114.114.114.114\n  - [/snnu.edu.cn/]114.114.114.114\n  - [/ipip.net/]114.114.114.114\n  - [/chinaz.com/]114.114.114.114\n  filtering_enabled: false\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules: []\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n");
		fclose(yaml);
	return 0;
}