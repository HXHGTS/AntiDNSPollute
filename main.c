#include<stdio.h>
#include<stdlib.h>

int mode;
FILE* yaml;
int main() {
	MainMenu:system("cls");
	printf("��ѡ��DNS���������з�ʽ��\n\n1.ģʽ1��������ͨ����DNS���������������ᱻ��Ⱦ���ʺ�һ�㺣����վ��\n\n2.ģʽ2�����б���DNS���ʺ����к�����վ����Ҫ�رձ������뵯�����ڣ�ÿ�ο�����Ҫ���´򿪣�\n\n3.�ָ�Ĭ��DNS������ģʽ2ʱ��С�Ĺرձ����ڣ����ô�ѡ��ָ��������ܣ�\n\n4.DNS����������ԣ�������ģʽ2��DNS״̬�������¿�һ�����򴰿������ԣ�\n\n�����룺");
	scanf("%d", &mode);
	system("cls");
	if (mode == 2) {
		Config_gen();
		printf("���ڽ�DNS��������������Ϊ���ؽ��������ܻ��б������Լ��ɣ�. . .\n\n");
		system("netsh interface ip set dns \"��̫��\" static 127.0.0.1");
		system("netsh interface ip set dns \"WLAN\" static 127.0.0.1");
		system("ipconfig /flushdns");
		printf("\n���ڲ���DNS����������. . .\n\n");
		printf("ע�⣺����ֹͣDNS����������ȹرյ������ڣ����ڱ������а�������ָ�Ĭ��DNS���ã�����ᵼ���޷�����������\n\n");
		system("start "" /min AdGuardHome.exe");
		printf("����ָ�Ĭ��DNS���ã����ȹرյ������ڣ�Ȼ��");
		system("pause");
		system("netsh interface ip set dns \"��̫��\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		system("ipconfig /flushdns");
		printf("\nDNS�����������ѳɹ��ָ���ʼ���ã�\n\n");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 3) {
		system("netsh interface ip set dns \"��̫��\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		printf("DNS�����������ѳɹ��ָ���ʼ���ã�\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 1) {
		system("netsh interface ip set dns \"��̫��\" static 101.133.211.12");
		system("netsh interface ip set dns \"WLAN\" static 101.133.211.12");
		printf("DNS�����������ѳɹ�����Ϊ��ͨ����DNS��\n\n");
		printf("��ģʽ�£��ȸ衢�͹ܡ����顢���ص����������Իᱻ��Ⱦ��\n\n");
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