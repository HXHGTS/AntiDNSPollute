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
		system("netsh interface ipv6 set dns \"��̫��\" static ::1");
		system("netsh interface ip set dns \"WLAN\" static 127.0.0.1");
		system("netsh interface ipv6 set dns \"WLAN\" static ::1");
		system("ipconfig /flushdns");
		system("cls");
		printf("���ڽ���DNS�������. . .\n\n");
		printf("���ڼ�������վ. . .\n\n");
		printf("���ڼ��ٶȽ������. . .\n\n");
		system("nslookup www.baidu.com 127.0.0.1");
		printf("���ڼ����Ѷ�������. . .\n\n");
		system("nslookup www.qq.com 127.0.0.1");
		printf("���ڼ��Ӣ�����˽������. . .\n\n");
		system("nslookup lol.qq.com 127.0.0.1");
		printf("���ڼ��������ҫ�������. . .\n\n");
		system("nslookup pvp.qq.com 127.0.0.1");
		printf("���ڼ�⾳����վ. . .\n\n");
		printf("���ڼ��ȸ�������. . .\n\n");
		system("nslookup www.google.com 127.0.0.1");
		printf("���ڼ���͹ܽ������. . .\n\n");
		system("nslookup www.youtube.com 127.0.0.1");
		printf("���ڼ������������. . .\n\n");
		system("nslookup www.facebook.com 127.0.0.1");
		printf("���ڼ�����ؽ������. . .\n\n");
		system("nslookup twitter.com 127.0.0.1");
		printf("���ڼ��Twitch�������. . .\n\n");
		system("nslookup www.twitch.tv 127.0.0.1");
		printf("����ɶ�DNS�����ļ�⣡\n\n");
		printf("DNS����ɹ���\n\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("ʹ�÷���ȾDNS�ڼ��벻Ҫ�رձ����ڼ��䵯�����ڣ���̨��С������. . .\n");
		printf("ע�⣺����ֹͣDNS����������ڱ������а�������ָ�Ĭ��DNS���ã�����ᵼ���޷�����������\n");
		printf("�����С�Ĺرձ�������������´򿪱����ʹ��ģʽ3�ָ�Ĭ��DNS������\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("����ָ�Ĭ��DNS���ã�");
		system("pause");
		system("taskkill /f /im AdGuardHome.exe");
		system("netsh interface ip set dns \"��̫��\" dhcp");
		system("netsh interface ipv6 set dns \"��̫��\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		system("netsh interface ipv6 set dns \"WLAN\" dhcp");
		system("ipconfig /flushdns");
		printf("\nDNS�����������ѳɹ��ָ���ʼ���ã�\n\n");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 3) {
		system("taskkill /f /im AdGuardHome.exe");
		system("netsh interface ip set dns \"��̫��\" dhcp");
		system("netsh interface ipv6 set dns \"��̫��\" dhcp");
		system("netsh interface ip set dns \"WLAN\" dhcp");
		system("netsh interface ipv6 set dns \"WLAN\" dhcp");
		printf("DNS�����������ѳɹ��ָ���ʼ���ã�\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 1) {
		printf("���ܻ���ֽϳ�ʱ������������ĵȴ�. . .\n");
		system("netsh interface ip set dns \"��̫��\" static 1.2.4.8");
		system("netsh interface ip add dns \"��̫��\" 210.2.4.8 index=2");
		system("netsh interface ip set dns \"WLAN\" static 1.2.4.8");
		system("netsh interface ip add dns \"WLAN\" 210.2.4.8 index=2");
		printf("DNS�����������ѳɹ�����ΪCNNIC DNS��\n\n");
		printf("��ģʽ�£��ȸ衢�͹ܡ����顢���ء�Twitch�����������Իᱻ��Ⱦ��\n\n");
		printf("��Ҫ��ȫ��������������ʹ��ģʽ2��\n\n");
		system("ipconfig /flushdns");
		system("pause");
		goto MainMenu;
	}
	else if (mode == 4) {
		system("ipconfig /flushdns");
		printf("\n���ڽ���DNS�������. . .\n\n");
		printf("���ڼ�������վ. . .\n\n");
		printf("���ڼ��ٶȽ������. . .\n\n");
		system("nslookup www.baidu.com");
		printf("���ڼ����Ѷ�������. . .\n\n");
		system("nslookup www.qq.com");
		printf("���ڼ��Ӣ�����˽������. . .\n\n");
		system("nslookup lol.qq.com");
		printf("���ڼ��������ҫ�������. . .\n\n");
		system("nslookup pvp.qq.com");
		printf("���ڼ�⾳����վ. . .\n\n");
		printf("���ڼ��ȸ�������. . .\n\n");
		system("nslookup www.google.com");
		printf("���ڼ���͹ܽ������. . .\n\n");
		system("nslookup www.youtube.com");
		printf("���ڼ������������. . .\n\n");
		system("nslookup www.facebook.com");
		printf("���ڼ�����ؽ������. . .\n\n");
		system("nslookup twitter.com");
		printf("���ڼ��Twitch�������. . .\n\n");
		system("nslookup www.twitch.tv");
		printf("�ɽ���������ip��ַ��������ping�����м��DNS��Ⱦ�����\n\n");
		printf("����ɶ�DNS�����ļ�⣬");
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
		fprintf(yaml, "bind_host: 0.0.0.0\nbind_port: 80\nusers:\n- name: root\n  password: $2a$10$mdmUKhmmhuDQO8GHlU.8xOWzwG6Fy.5o5YUCUWYg2DkyfgYRsM0hy\nhttp_proxy: ""\nlanguage: ""\nrlimit_nofile: 0\nweb_session_ttl: 720\ndns:\n  bind_host: 0.0.0.0\n  port: 53\n  statistics_interval: 1\n  querylog_enabled: false\n  querylog_interval: 90\n  querylog_size_memory: 1000\n  anonymize_client_ip: false\n  protection_enabled: true\n  blocking_mode: default\n  blocking_ipv4: \"\"\n  blocking_ipv6: \"\"\n  blocked_response_ttl: 10\n  ratelimit: 0\n  ratelimit_whitelist: []\n  refuse_any: true\n  bootstrap_dns:\n  - 1.2.4.8\n  all_servers: true\n  edns_client_subnet: true\n  enable_dnssec: false\n  aaaa_disabled: false\n  allowed_clients: []\n  disallowed_clients: []\n  blocked_hosts: []\n  parental_block_host: family-block.dns.adguard.com\n  safebrowsing_block_host: standard-block.dns.adguard.com\n  cache_size: 0\n  cache_ttl_min: 0\n  cache_ttl_max: 0\n  upstream_dns:\n  - tls://17829026230.rubyfish.cn\n  - '[/netease.com/]1.2.4.8'\n  - '[/126.net/]1.2.4.8'\n  - '[/icourse163.org/]1.2.4.8'\n  - '[/yeah.net/]1.2.4.8'\n  - '[/126.com/]1.2.4.8'\n  - '[/163.com/]1.2.4.8'\n  - '[/zhangmuhan.club/]1.2.4.8'\n  - '[/google.cn/]1.2.4.8'\n  - '[/baidu.com/]1.2.4.8'\n  - '[/baidupcs.com/]1.2.4.8'\n  - '[/bdstatic.com/]1.2.4.8'\n  - '[/bilibili.com/]1.2.4.8'\n  - '[/bilivideo.com/]1.2.4.8'\n  - '[/hdslb.com/]1.2.4.8'\n  - '[/qq.com/]1.2.4.8'\n  - '[/douyu.com/]1.2.4.8'\n  - '[/huya.com/]1.2.4.8'\n  - '[/aliyun.com/]1.2.4.8'\n  - '[/alicdn.com/]1.2.4.8'\n  - '[/alipay.com/]1.2.4.8'\n  - '[/taobao.com/]1.2.4.8'\n  - '[/tmall.com/]1.2.4.8'\n  - '[/jd.com/]1.2.4.8'\n  - '[/zxxk.com/]1.2.4.8'\n  - '[/cnzz.com/]1.2.4.8'\n  - '[/chaoxing.com/]1.2.4.8'\n  - '[/snnu.edu.cn/]1.2.4.8'\n  - '[/ipip.net/]1.2.4.8'\n  - '[/7moor.com/]1.2.4.8'\n  - '[/t.cn/]1.2.4.8'\n  - '[/chinaz.com/]1.2.4.8'\n  - '[/uzer.me/]1.2.4.8'\n  - '[/lanzou.com/]1.2.4.8'\n  - '[/lanzous.com/]1.2.4.8'\n  - '[/baidupan.com/]1.2.4.8'\n  - '[/zhihu.com/]1.2.4.8'\n  - '[/zhihu.com/]1.2.4.8'\n  - '[/zhimg.com/]1.2.4.8'\n  - '[/cnki.net/]1.2.4.8'\n  - '[/iqiyi.com/]1.2.4.8'\n  - '[/qy.net/]1.2.4.8'\n  - '[/iqiyipic.com/]1.2.4.8'\n  - '[/acfun.cn/]1.2.4.8'\n  - '[/aixifan.com/]1.2.4.8'\n  - '[/yximgs.com/]1.2.4.8'\n  - '[/ksurl.cn/]1.2.4.8'\n  - '[/139.com/]1.2.4.8'\n  - '[/10086.cn/]1.2.4.8'\n  - '[/189.cn/]1.2.4.8'\n  - '[/knet.cn/]1.2.4.8'\n  - '[/10010.cn/]1.2.4.8'\n  - '[/10010.com/]1.2.4.8'\n  - '[/weibo.com/]1.2.4.8'\n  - '[/sina.com.cn/]1.2.4.8'\n  - '[/sohu.com/]1.2.4.8'\n  - '[/cctv.cn/]1.2.4.8'\n  - '[/nn.com/]1.2.4.8'\n  - '[/xunyou.com/]1.2.4.8'\n  - '[/leigod.com/]1.2.4.8'\n  - '[/steampowered.com/]1.2.4.8'\n  - '[/eccdnx.com/]1.2.4.8'\n  - '[/iplaysoft.com/]1.2.4.8'\n  - '[/jianshu.com/]1.2.4.8'\n  filtering_enabled: true\n  filters_update_interval: 24\n  parental_enabled: false\n  safesearch_enabled: false\n  safebrowsing_enabled: false\n  safebrowsing_cache_size: 1048576\n  safesearch_cache_size: 1048576\n  parental_cache_size: 1048576\n  cache_time: 30\n  rewrites: []\n  blocked_services: []\ntls:\n  enabled: false\n  server_name: \"\"\n  force_https: false\n  port_https: 443\n  port_dns_over_tls: 853\n  allow_unencrypted_doh: false\n  strict_sni_check: false\n  certificate_chain: \"\"\n  private_key: \"\"\n  certificate_path: \"\"\n  private_key_path: \"\"\nfilters: []\nwhitelist_filters: []\nuser_rules:\n- 192.108.239.108 video-weaver.lhr03.hls.ttvnw.net\n- \"\"\ndhcp:\n  enabled: false\n  interface_name: \"\"\n  gateway_ip: \"\"\n  subnet_mask: \"\"\n  range_start: \"\"\n  range_end: \"\"\n  lease_duration: 86400\n  icmp_timeout_msec: 1000\nclients: []\nlog_file: \"\"\nverbose: false\nschema_version: 6\n");
		fclose(yaml);
	return 0;
}