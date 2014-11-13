<?php
/**
 * @file
 * hid_auth.oauthconnector.inc
 */

/**
 * Implements hook_default_oauthconnector_provider().
 */
function hid_auth_default_oauthconnector_provider() {
  $export = array();

  $provider = new stdClass();
  $provider->disabled = FALSE; /* Edit this to true to make a default provider disabled initially */
  $provider->api_version = 1;
  $provider->name = 'hid_oauth';
  $provider->title = 'Humanitarian ID Oauth';
  $provider->url = 'http://hid.local:3000';
  $provider->consumer_advanced = array(
    'oauth2' => 1,
    'signature method' => 'HMAC-SHA1',
    'authentication realm' => '',
    'request token endpoint' => '/oauth/request_token',
    'authorization scope' => 'hid:full',
    'authorization endpoint' => '/oauth/authorize',
    'access token endpoint' => '/oauth/access_token',
  );
  $provider->mapping = array(
    'fields' => array(
      'uid' => array(
        'resource' => 'http://hid.local:3000/account.json',
        'method post' => 0,
        'field' => 'user_id',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'email' => array(
        'resource' => 'http://hid.local:3000/account.json',
        'method post' => 0,
        'field' => 'email',
        'querypath' => FALSE,
        'sync_with_field' => 'mail',
      ),
      'name' => array(
        'resource' => '',
        'method post' => 0,
        'field' => '',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
      'name' => array(
        'resource' => 'http://hid.local:3000/account.json',
        'method post' => 0,
        'field' => 'email',
        'querypath' => FALSE,
        'sync_with_field' => 'name',
      ),
      'avatar' => array(
        'resource' => '',
        'method post' => 0,
        'field' => '',
        'querypath' => FALSE,
        'sync_with_field' => '',
      ),
    ),
    'format' => 'json',
  );
  $export['hid_oauth'] = $provider;

  return $export;
}
