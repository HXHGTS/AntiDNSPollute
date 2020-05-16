#include<stdio.h>
#include<stdlib.h>
int Boot();
int UserInterface();
int RunLocalDNSServer();
int NetFixTool();
int WeakDNSMode();
int ConfigEditor();
int ConfigToDefault();
int NSTool();
int Help();
int FixHosts();
int Config_gen();
int Reset();

int mode,DNSSet,fixmode,DNSServer,ADSwitch;
FILE* yaml,*AdGuardHome,*SystemHosts,*bak,*ADFilter;
char TopDNS[200],Hosts[600], ADFilterRules[600],WhiteList[2200];

int main() {
MainMenu:system("cls");
	UserInterface();
	if (mode == 2) {
		Boot();
		RunLocalDNSServer();
		goto MainMenu;
	}
	else if (mode == 3) {
		NetFixTool();
		goto MainMenu;
	}
	else if (mode == 1) {
		WeakDNSMode();
		goto MainMenu;
	}
	else if (mode == 4) {
		Reset();
		Boot();
		ConfigEditor();
		goto MainMenu;
}
	else if (mode == 5) {
		Boot();
		ConfigToDefault();
		goto MainMenu;
}
	else if (mode == 6) {
		NSTool();
		goto MainMenu;
	}
	else if (mode == 7) {
		FixHosts();
		goto MainMenu;
	}
	else if (mode == 0) {
		Help();
		goto MainMenu;
}
	else {
		goto MainMenu;
	}
	return 0;
}

int Config_gen() {
	sprintf(TopDNS, "  - 208.67.222.222:5353\n  - 208.67.220.220:5353\n  - 208.67.222.220:5353\n  - 208.67.220.222:5353\n  - 208.67.222.222:443\n  - 208.67.220.220:443\n  - 208.67.222.220:443\n  - 208.67.220.222:443\n");
	sprintf(WhiteList, "  - '[/netease.com/]119.29.29.29'\n  - '[/126.net/]119.29.29.29'\n  - '[/icourse163.org/]119.29.29.29'\n  - '[/yeah.net/]119.29.29.29'\n  - '[/126.com/]119.29.29.29'\n  - '[/163.com/]119.29.29.29'\n  - '[/google.cn/]119.29.29.29'\n  - '[/baidu.com/]119.29.29.29'\n  - '[/baidupcs.com/]119.29.29.29'\n  - '[/bdstatic.com/]119.29.29.29'\n  - '[/bilibili.com/]119.29.29.29'\n  - '[/bilivideo.com/]119.29.29.29'\n  - '[/akamaized.net/]119.29.29.29'\n  - '[/hdslb.com/]119.29.29.29'\n  - '[/qq.com/]119.29.29.29'\n  - '[/douyu.com/]119.29.29.29'\n  - '[/huya.com/]119.29.29.29'\n  - '[/aliyun.com/]119.29.29.29'\n  - '[/alicdn.com/]119.29.29.29'\n  - '[/alipay.com/]119.29.29.29'\n  - '[/taobao.com/]119.29.29.29'\n  - '[/tmall.com/]119.29.29.29'\n  - '[/jd.com/]119.29.29.29'\n  - '[/zxxk.com/]119.29.29.29'\n  - '[/cnzz.com/]119.29.29.29'\n  - '[/chaoxing.com/]119.29.29.29'\n  - '[/snnu.edu.cn/]119.29.29.29'\n  - '[/ipip.net/]119.29.29.29'\n  - '[/7moor.com/]119.29.29.29'\n  - '[/t.cn/]119.29.29.29'\n  - '[/chinaz.com/]119.29.29.29'\n  - '[/uzer.me/]119.29.29.29'\n  - '[/lanzou.com/]119.29.29.29'\n  - '[/lanzous.com/]119.29.29.29'\n  - '[/baidupan.com/]119.29.29.29'\n  - '[/v.smtcdns.com/]119.29.29.29'\n  - '[/youku.com/]119.29.29.29'\n  - '[/ott.cibntv.net/]119.29.29.29'\n  - '[/zhihu.com/]119.29.29.29'\n  - '[/zhimg.com/]119.29.29.29'\n  - '[/cnki.net/]119.29.29.29'\n  - '[/iqiyi.com/]119.29.29.29'\n  - '[/qy.net/]119.29.29.29'\n  - '[/iqiyipic.com/]119.29.29.29'\n  - '[/acfun.cn/]119.29.29.29'\n  - '[/aixifan.com/]119.29.29.29'\n  - '[/yximgs.com/]119.29.29.29'\n  - '[/ksurl.cn/]119.29.29.29'\n  - '[/139.com/]119.29.29.29'\n  - '[/10086.cn/]119.29.29.29'\n  - '[/189.cn/]119.29.29.29'\n  - '[/knet.cn/]119.29.29.29'\n  - '[/10010.cn/]119.29.29.29'\n  - '[/10010.com/]119.29.29.29'\n  - '[/weibo.com/]119.29.29.29'\n  - '[/sina.com.cn/]119.29.29.29'\n  - '[/sohu.com/]119.29.29.29'\n  - '[/cctv.cn/]119.29.29.29'\n  - '[/nn.com/]119.29.29.29'\n  - '[/xunyou.com/]119.29.29.29'\n  - '[/leigod.com/]119.29.29.29'\n  - '[/steampowered.com/]119.29.29.29'\n  - '[/eccdnx.com/]119.29.29.29'\n  - '[/iplaysoft.com/]119.29.29.29'\n  - '[/jianshu.com/]119.29.29.29'\n  - '[/edu.cn/]119.29.29.29'\n  - '[/gov.cn/]119.29.29.29'\n  ");
	sprintf(Hosts, "- 151.101.248.133 raw.githubusercontent.com\n- \"\"\n");
	printf("注意：节点1、2为国内节点，解析速度更快，但可能会留下解析日志，使用请注意！\n\n");
	printf("指定上游DNS服务器区域：\n\n1.红鱼DNS（阿里云+腾讯云）（加密解析，但服务器在国内，安全性低，解析速度快，适合游戏）\n\n2.GeekDNS（百度云）（加密解析，但服务器在国内，安全性低，解析速度快，适合游戏）\n\n3.Cisco OpenDNS（中国香港）（非标准端口下解析，服务器在国外，安全性低，解析速度快，适合游戏）\n\n4.GoogleDNS（美国中部）（加密解析，服务器在国外，安全性高）\n\n5.AdGuardDNS（俄罗斯）（加密解析，服务器在国外，安全性高）\n\n6.IBM Quad9（美国中部）（加密解析，服务器在国外，安全性高）\n\n7.CloudflareDNS（中国香港）（加密解析，服务器在国外，无日志记录，安全性极高）\n\n8.SWITCH.CH DNS（瑞士苏黎世、洛桑）（加密解析，服务器在中立国，安全性极高）\n\n请输入：");
	scanf("%d", &DNSServer);
	system("cls");
	printf("广告拦截模式：\n\n1.开启Adblock Plus拦截\n\n2.开启AdGuard拦截\n\n3.不拦截\n\n请输入：");
	scanf("%d", &ADSwitch);
		yaml = fopen("index.yaml", "w");
		if (ADSwitch == 1) {
			sprintf(ADFilterRules, "\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/abp-filters-anti-cv.txt\n  name: ABP filters\n  id: 1588581704\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/easyprivacy.txt\n  name: EasyPrivacy\n  id: 1588581706\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/fanboy-social.txt\n  name: Fanboy's Social Blocking List\n  id: 1588581707\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/easylistchina+easylist.txt\n  name: EasyList China+EasyList\n  id: 1588581708\n");

		}
		 else if (ADSwitch == 2) {
			sprintf(ADFilterRules, "\n- enabled: true\n  url: https://filters.adtidy.org/extension/chromium/filters/2.txt\n  name: AdGuard Base filter\n  id: 1589448814\n- enabled: true\n  url: https://filters.adtidy.org/extension/chromium/filters/3.txt\n  name: AdGuard Tracking Protection filter\n  id: 1589448815\n- enabled: true\n  url: https://filters.adtidy.org/extension/chromium/filters/4.txt\n  name: AdGuard Social Media filter\n  id: 1589448816\n- enabled: true\n  url: https://easylist-downloads.adblockplus.org/easylistchina.txt\n  name: EasyList China\n  id: 1589448817\n");
		}
		else {
			sprintf(ADFilterRules, "[]\n");
		}
		if (DNSServer == 1)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS,"  - tls://dns.rubyfish.cn\n", WhiteList, ADFilterRules,Hosts);
		else if (DNSServer == 2)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS, "  - https://i.233py.com/dns-query\n", WhiteList, ADFilterRules, Hosts);
		else if (DNSServer == 3)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS, "  - 208.67.222.222:5353\n  - 208.67.220.220:5353\n  - 208.67.222.220:5353\n  - 208.67.220.222:5353\n  - 208.67.222.222:443\n  - 208.67.220.220:443\n  - 208.67.222.220:443\n  - 208.67.220.222:443\n", WhiteList, ADFilterRules, Hosts);
		else if (DNSServer == 4)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS, "  - tls://dns.google\n  - https://dns.google/dns-query\n", WhiteList, ADFilterRules, Hosts);
		else if (DNSServer == 5)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS, "  - tls://dns.adguard.com\n  - https://dns.adguard.com/dns-query\n", WhiteList, ADFilterRules, Hosts);
		else if (DNSServer == 6)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS, "  - https://dns.quad9.net/dns-query\n  - tls://dns.quad9.net\n", WhiteList, ADFilterRules, Hosts);
		else if (DNSServer == 7)fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS, "  - tls://1dot1dot1dot1.cloudflare-dns.com\n  - https://dns.cloudflare.com/dns-query\n", WhiteList, ADFilterRules, Hosts);
		else fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n%s  all_servers: true\n  fastest_addr: false\n  edns_client_subnet: true\n  enable_dnssec: true\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n%s%sfiltering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: %swhitelist_filters: []\nuser_rules:\n%sdhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n", TopDNS, "  - https://dns.switch.ch/dns-query\n  - tls://dns.switch.ch\n", WhiteList, ADFilterRules, Hosts);
		fclose(yaml);
		system("cls");
		if(DNSServer==1)printf("\n已选定：%s\n\n","红鱼DNS（阿里云+腾讯云）");
		else if (DNSServer == 2)printf("\n已选定：%s\n\n", "GeekDNS（百度云）");
		else if (DNSServer == 3)printf("\n已选定：%s\n\n", "Cisco OpenDNS（中国香港）");
		else if (DNSServer == 4)printf("\n已选定：%s\n\n", "GoogleDNS（美国中部）");
		else if (DNSServer == 5)printf("\n已选定：%s\n\n", "AdGuardDNS（俄罗斯）");
		else if (DNSServer == 6)printf("\n已选定：%s\n\n", "IBM Quad9（美国中部）");
		else if (DNSServer == 7)printf("\n已选定：%s\n\n", "CloudflareDNS（中国香港）");
		else printf("\n已选定：%s\n\n", "SWITCH.CH DNS（瑞士苏黎世、洛桑）");
		if (ADSwitch == 1)printf("%s\n\n","已开启Adblock Plus广告拦截功能");
		else if (ADSwitch == 2)printf("%s\n\n", "已开启AdGuard广告拦截功能");
		else printf("%s\n\n", "已关闭广告拦截功能");
	return 0;
}

int WeakDNSMode() {
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
	if (DNSSet == 1)printf("DNS解析服务器已成功设置为%s！\n\n", "韩国KT DNS");
	else if (DNSSet == 2)printf("DNS解析服务器已成功设置为%s！\n\n", "韩国SK DNS");
	else if (DNSSet == 3)printf("DNS解析服务器已成功设置为%s！\n\n", "韩国LG U+ DNS");
	else if (DNSSet == 4)printf("DNS解析服务器已成功设置为%s！\n\n", "台湾中华电信HiNet DNS");
	else if (DNSSet == 5)printf("DNS解析服务器已成功设置为%s！\n\n", "台湾TWNIC DNS");
	else printf("DNS解析服务器已成功设置为%s！\n\n", "中国大陆CNNIC DNS");
	printf("此模式下，谷歌、油管、脸书、推特、Twitch等敏感域名仍会被污染！\n\n");
	printf("需要完全解析敏感域名请使用模式2！\n\n");
	system("ipconfig /flushdns");
	system("pause");
	return 0;
}

int NetFixTool() {
	Reset();
	printf("DNS解析服务器已成功恢复初始设置！\n\n");
	system("ipconfig /flushdns");
	system("pause");
	return 0;
}

int Reset() {
	system("taskkill /f /im AdGuardHome.exe");
	system("del AdGuardHome.yaml");
	system("rmdir /s/q data");
	system("rmdir /s/q agh-backup");
	system("netsh interface ip set dns \"以太网\" dhcp");
	system("netsh interface ipv6 set dns \"以太网\" dhcp");
	system("netsh interface ip set dns \"WLAN\" dhcp");
	system("netsh interface ipv6 set dns \"WLAN\" dhcp");
	return 0;
}

int RunLocalDNSServer() {
	printf("正在初始化. . .\n\n");
	Reset();
	printf("\n正在准备配置文件. . .\n\n");
	system("copy index.yaml AdGuardHome.yaml");
	printf("\n正在部署DNS解析服务器. . .\n\n");
	system("start "" /min AdGuardHome.exe");
	printf("正在将DNS解析服务器设置为本地解析（可能会有报错，忽略即可）. . .\n\n");
	system("netsh interface ip set dns \"以太网\" static 127.0.0.1");
	system("netsh interface ipv6 set dns \"以太网\" static ::1");
	system("netsh interface ip set dns \"WLAN\" static 127.0.0.1");
	system("netsh interface ipv6 set dns \"WLAN\" static ::1");
	system("ipconfig /flushdns");
	system("cls");
	printf("准备验证DNS，请耐心等待5s，不要退出. . .\n\n");
	system("TIMEOUT /T 5 /NOBREAK");
	printf("\n正在进行DNS解析检测. . .\n\n");
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
	printf("已完成所有DNS解析的检测！\n\n");
	printf("DNS部署成功！\n\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("注意：使用防污染DNS期间请不要关闭本窗口及其弹出窗口，后台最小化即可！！！\n");
	printf("如需停止DNS解析请务必在本窗口中按任意键恢复默认DNS设置，否则会导致无法上网！！！\n");
	printf("如果不小心关闭本软件，可以重新打开本软件使用模式3恢复默认DNS！！！\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("如需恢复默认DNS设置，");
	system("pause");
	system("taskkill /f /im AdGuardHome.exe");
	system("del AdGuardHome.yaml");
	system("rmdir /s/q data");
	system("rmdir /s/q agh-backup");
	system("netsh interface ip set dns \"以太网\" dhcp");
	system("netsh interface ipv6 set dns \"以太网\" dhcp");
	system("netsh interface ip set dns \"WLAN\" dhcp");
	system("netsh interface ipv6 set dns \"WLAN\" dhcp");
	system("ipconfig /flushdns");
	printf("\nDNS解析服务器已成功恢复初始设置！\n\n");
	system("pause");
	return 0;
}

int ConfigEditor() {
	printf("请选择修改方式：\n\n1.图形界面（用户名与密码默认均为root）\n\n2.记事本\n\n请输入：");
	scanf("%d", &fixmode);
	if (fixmode == 2) {
		if ((yaml = fopen("index.yaml", "r")) == NULL) {
			Config_gen();
		}
		system("copy /y index.yaml index.yaml.bak");
		system("notepad.exe index.yaml");
		printf("\n请在弹出窗口中修改配置文件后，");
		system("pause");
	}
	else {
		printf("正在准备配置文件. . .\n\n");
		system("copy /y index.yaml index.yaml.bak");
		system("copy index.yaml AdGuardHome.yaml");
		printf("正在部署DNS解析服务器. . .\n\n");
		system("start "" /min AdGuardHome.exe");
		system("explorer.exe http://127.0.0.1");
		printf("\n请在弹出窗口中修改配置文件后，");
		system("pause");
		system("taskkill /f /im AdGuardHome.exe");
		system("copy AdGuardHome.yaml index.yaml");
		system("del AdGuardHome.yaml");
		system("rmdir /s/q data");
		system("rmdir /s/q agh-backup");
	}
	return 0;
}

int ConfigToDefault() {
	if ((bak = fopen("index.yaml.bak", "r") != NULL)){
		printf("软件目录中找到上次的配置备份，请选择恢复模式：\n\n1.恢复到上一次的配置\n\n2.恢复初始状态\n\n请输入：");
		scanf("%d", &fixmode);
		if (fixmode == 1) {
			system("copy /y index.yaml.bak index.yaml");
			printf("\n已成功恢复到上一次的配置！\n");
			return 0;
		}
	}
	system("cls");
	Config_gen();
	printf("\n已成功恢复初始状态！\n");
	system("pause");
	return 0;
}

int NSTool() {
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
	return 0;
}

int Help() {
	printf("正在打开在线帮助. . .\n");
	system("explorer https://hxhgts.github.io/AntiDNSPollute/");
	return 0;
}

int Boot() {
	mode = 0;
	if ((AdGuardHome = fopen("AdGuardHome.exe", "r")) == NULL) {
		printf("未在软件目录中发现AdGuardHome引擎，请在官网下载后放置在本软件同一目录下！\n\n");
		system("pause");
		exit(0);
	}
	if ((yaml = fopen("index.yaml", "r")) == NULL) {
		Config_gen();
		printf("模式2配置文件已生成！\n\n");
		system("pause");
	}
	system("cls");
	return 0;
}

int FixHosts() {
	printf("正在恢复默认Hosts文件. . .\n\n");
	SystemHosts = fopen("hosts", "w");
	fprintf(SystemHosts, "");
	fclose(SystemHosts);
	system("del %windir%\\System32\\drivers\\etc\\hosts");
	system("copy hosts %windir%\\System32\\drivers\\etc\\hosts");
	system("del hosts");
	system("ipconfig /flushdns");
	printf("\n已成功恢复默认Hosts文件！\n\n");
	system("pause");
	system("cls");
	return 0;
}

int UserInterface() {
	printf("请选择DNS服务器运行方式：\n\n1.模式1：设置普通级别DNS解析（修改完成可以关闭本程序，部分域名会被污染）\n\n2.模式2：运行本地DNS（使用时不要关闭本窗口与弹出窗口，每次使用需要重新打开）\n\n3.模式3：恢复默认DNS（运行模式2时未正常退出，可用此选项恢复上网功能）\n\n4.自定义DNS配置文件（用于添加自定义上游）\n\n5.恢复默认配置文件（自定义失败时可用于恢复默认，用户名密码也将被重置）\n\n6.当前DNS解析结果测试\n\n7.重置系统Hosts文件\n\n0.在线帮助\n\n请输入：");
	scanf("%d", &mode);
	system("cls");
	return 0;
}