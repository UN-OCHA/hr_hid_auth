<?php
/**
 * @file
 * hid_auth.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hid_auth_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "oauthconnector" && $api == "oauthconnector") {
    return array("version" => "1");
  }
}
